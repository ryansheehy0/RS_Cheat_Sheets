[Home](../README.md)

# Serial Communication
The purpose of serial communication is to transfer information between devices while using fewer wires than parallel communication.

- Light(AM and FM)
- Ti Calculators
- USB Serial Protocol
- UART
- I2C
- Can Bus

## Terms
- **Synchronous** - Uses a clock signal to 
	- **Asynchronous** - Doesn't have a clock signal and relies on a predetermined time for each bit(**baud rate**).
	-
	- precise timing and eliminating the need for start/stop bits. This allows for faster and more efficient data transfer compared to asynchronous communication. It's commonly used in

- Synchronous(Uses clock) vs Asynchronous
- Half duplex - Only one device can send/receive data at a time.
- Differential
	- Instead of using 0v and +V which can get corrupted with noise, you use -V and +V usually wrapped around each other, thus canceling any noise.
		- The difference between -V and +V is a 1 or 0.
- CRC and error correction
	- Cyclic Redundancy Check
	
	Here are some common variables used to understand serial communication protocols:

Synchronous vs. Asynchronous – Synchronous uses a clock signal; asynchronous does not.
Half-Duplex vs. Full-Duplex – Half-duplex allows one device to send/receive at a time, while full-duplex allows both simultaneously.
Differential Signaling – Uses -V and +V instead of 0V and +V to reduce noise interference.
Baud Rate – The speed of data transmission, measured in bits per second (bps).
CRC and Error Correction – Cyclic Redundancy Check and other methods ensure data integrity.






You said:
Are there more?
ChatGPT said:
Yes, here are additional key variables in serial communication protocols:

Bit Order (Endianness) – Determines whether the most significant bit (MSB) or least significant bit (LSB) is sent first.
Parity Bit – Used for basic error detection (Even, Odd, None).
Stop Bits – Define the end of a data packet (e.g., 1, 1.5, or 2 bits).
Flow Control – Manages data flow to prevent buffer overflows (e.g., XON/XOFF for software, RTS/CTS for hardware).
Framing – Defines how data is structured, including start bits, data length, parity, and stop bits.
Voltage Levels – Specifies signal levels, such as RS-232 (±12V) vs. TTL (0V/5V).
Protocol-Specific Features – Some protocols (e.g., SPI, I²C, CAN) include unique properties like multi-master support or address-based communication.

## Other common ports
- ADC - Analog to digital converter
- DAC - Digital to analog converter
- PWM - Pulse width modulation
- Power
	- AVDD - Analog Voltage Drain.

## UART - Universal Asynchronous Receiver/Transmitter
- Transmit at a baud rate/symbols per second(usually bits per second)
- USART adds a clock line to allow for synchronous communication.
- Ports
	- TX - Transmit
	- RX - Receive
	- GND - Ground
	- RTS(Optional) - Request to send. Transmitting device *requests to send* data.
	- DTR(Optional) - Data Terminal Ready. Transmitting device tells receiving device that it's powered and ready to communicate.
	- CTS(Optional) - Clear to send. Receiving device says to the transmitting device that it's *clear to send* data.

## SPI - Serial Peripheral Interface
- Ports
	- CS - Chip select
	- SCK - Serial clock signal
	- MOSI - Master out slave in
	- MISO - Master in slave out
- QSPI - Quad SPI. 2 MOSI and MISO.

## I2C - Inter Integrated Circuit
- Ports
	- SCL - Serial clock line
	- SDA - Serial data line
	- GND - Ground

## CAN - Controller area network
- Multiple devices connected together
	- All devices can send and receive data
	- Each device connects to the H and L lines.
		- Send ID then message
		- Only the device with the ID reads the message
- Half duplex - Only one device can send/receive data at a time.
- Asynchronous
- Ports
	- CANH - CAN High
	- CANL - CAN Low
	- Uses a CN transceiver(like TJA1040) to convert between TD/RD to CANH and CANL
		- TD - Transmit data.
		- RD - Receive data.
- Data package
	- Start bit
	- ID bits/Arbitration field
	- Control bit
	- Data
	- CRC bits
	- End frame bits

## Either CAT - Ethernet for control automation technology