# Quad Copter notes

```C++
calibrateSensors();
while (true) {
	tuple<Pitch, Roll, Yaw> sensorData = readSensorData();
	tuple<Pitch, Roll, Yaw, bool> userValues = readUserValues();
	controlMotors(sensorData, userValues);
}
```

## Calibrate
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

- Kalman filter
	- 

## Different drone modes
- Angle mode - Joystick changes tilt angle and drone auto levels itself to maintain that angle.
- Acro mode - Joystick changes the rate of change of the angle.
- Horizon mode - Small stick inputs behave like angle and large behave like acro.

## Controller modes
Mode 2:
- Left stick: Up/down Altitude, Left/right Yaw
- Right stick: Up/down pitch, Left/right Roll

- With QuadPlane
	- Right stick down: Pitch back.
	- Right stick up: Pitch forward until level, then forward prop.