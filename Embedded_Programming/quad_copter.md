# Quad Copter notes

```C++
#include "imu.h"


int main() {
	IMU imu;
	imu.calibrate();

	while (true) {
		tuple<Pitch, Roll, Yaw> sensorData = readSensorData();
		tuple<Pitch, Roll, Yaw, bool> userValues = readUserValues();
		controlMotors(sensorData, userValues);
	}
}
```

```C++
```

## Calibrate sensors

```C++
void IMU::calibrate() {
	const int CALIBRATION_SAMPLES = 2000;

	// Calibrate gyroscope
	RotationRates avgRates;
	for (int i = 0; i < CALIBRATION_SAMPLES; i++) {
		RotationRates gyroRates = gyro();
		avgRates.pitchRate += gyroRates.pitchRate;
		avgRates.rollRate += gyroRates.rollRate;
		avgRates.yawRate += gyroRates.yawRate;
	}
	gyroOffset.pitchRate = avgRates.pitchRate / CALIBRATION_SAMPLES;
	gyroOffset.rollRate = avgRates.rollRate / CALIBRATION_SAMPLES;
	gyroOffset.yawRate = avgRates.yawRate / CALIBRATION_SAMPLES;

	// Calibrate accelerometer
	Gravity
}
```

- Wait
- Take average of all of them
- Offset it's value by the average so it floats around 0.

- z axis should be calibrated to 1G, but x and y should be to 0.

- Do for both gyroscope and accelerometer

## readSensorData
### Gyroscope data
- Integrating the rotation angles with the gyroscope to get the pitch, roll, and yaw, but this has drift over time as errors are added up.
	- Not sensitive to vibrations, but drift over time.

```C++
deltaTime = (micors() - gyroLastUpdate) / 1'000'000;
gyroAngles.x += rates.x * deltaTime;
gyroLastUpdate - micros();
```

### Accelerometer data
- Roll and pitch gotten from accelerometer
	- $\theta_{pitch} = atan(\frac{-Acc_x}{\sqrt(Acc^{2}_{y} + Acc^{2}_{z})})$
	- $\theta_{roll} = atan(\frac{Acc_y}{\sqrt(Acc^{2}_{x} + Acc^{2}_{z})})$
	- The accelerometer can't measure yaw angle because its axis aligns with gravity.

- Make sure rad and degrees are correct.

- Accelerometer is heavily sensitive by vibration.

- Usually filtered to reduce noise
	- Low pass filter - Smooths data by averaging
	- Median filter - Replaces each value with the median of neighboring values.
		- Have a queue and a sum. Add element to queue and add to sum. Pop from queue and subtract from sum.
		- 11 values.
		- Sort the array, take the median and choose as your new value.

### Combine Gyroscope and Accelerometer data
- You need to combine accelerometer and gyroscope to remove both of their disadvantages.
	- This can't be done for yaw, so use acro mode for yaw control?
	- Gyroscope - Good for short durations
	- Accelerometer - Good for long durations
- Complementary filter - Easy, but less accurate

```C++
// Complementary filter
const float GYRO_WEIGHT = 0.995;
const float ACC_WEIGHT = 0.005;

deltaTime = // time since last update

angles.x = GYRO_WEIGHT * (angles.x + (rates.x * deltaTime)) + ACC_WEIGHT * accelAngles.x;
// Do same for y
```
- Madgwick filter
- Kalman filter
	- 

## Controller
### Different drone modes
- Angle/stabilized mode - Joystick changes tilt angle and drone auto levels itself to maintain that angle.
- Acro/rate mode - Joystick changes the rate of change of the angle.
	- Release the stick, the drone tries to stays at that angle.
	- Doesn't use accelerometer data.
- Horizon mode - Small stick inputs behave like angle and large behave like acro.

### Controller modes
Mode 2:
- Left stick: Up/down Altitude, Left/right Yaw
- Right stick: Up/down pitch, Left/right Roll

- With QuadPlane
	- Right stick down: Pitch back.
	- Right stick up: Pitch forward until level, then forward prop.

### read user values
- Pulse Position Modulation(PPM) - Transmit all control channels as one combined signal stream.
	- Saves pins ont he micro-controller
	- Simplifies wiring
	- Compact
- Convert the pulse range(micro-seconds) directly to an angle(in degrees).
	- Roll - (1000-2000) to (-25, 25)
	- Pitch - (1000-2000) to (-25, 25)
	- Throttle - (1000-2000) to (1000, 2000) Not an angle, but throttle.
	- Yaw - (1000-2000) to (-50, 50)

## Control motors
- The ESCs are made to work with the remote control.
	- Max is 2000 and min is 1000
- 4 values, between 2000 and 1000, for each motor.

```C++
motor1 = throttle - roll - pitch - yaw;
motor2 = throttle + roll + pitch - yaw;
motor3 = throttle - roll + pitch + yaw;
motor4 = throttle + roll - pitch + yaw;
```

- Where to get roll, pitch, and yaw values?
	- motorOutput PID(rotationalRateFromGyro, userValues)
		- The userValues are the setpoint and the sensorData is the actual rate from sensors.
	- Each PID loop for roll, pitch, and yaw.
	- Derivative susceptible to noise.
	- Error is calcualted based on the dif between sensor reading and pilot command

```C++
const double P = 2.0;
const double I = 2.0;
const double D = 2.0;

double error = desiredPitch - currentPitch;

proportional = P * error;
integral += I * error * deltaTime;
derivative = D * ((error - prevError) / deltaTime);
prevError = error;

output = proportional + integral + derivative;
```

- New PIDs for stabilization for pitch, roll, and yaw.
	- desiredRotationalRate = stabilizedPID(sensorDataFromAccelerometer, userValues)
	- motorOutput = ratePID(rotationalRateFromGyro, desiredRotationalRate)

## Safty
- Very important
- Build stand to tune PIDs
- Don't stand near when running/testing.

- Safety code checks
	- Stale/non changing IMU(gyro and accelerometer) values
	- Stale remote control values
	- Angles too high turn off motors.
	- Rate of change of angle too high
	- Motor outputs too high?(Indoor safe mode)