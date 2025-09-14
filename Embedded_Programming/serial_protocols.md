[Home](../README.md#embedded-programming)

# Serial Protocols
The purpose of serial communication is to transfer information between devices while using fewer wires than parallel communication.

- **Synchronous/Asynchronous** - Uses a clock signal/Doesn't use a clock signal.
- **Half-duplex/Full-duplex** - Only one device can send and receive data/Both devices can send and receive data.
- **Differential** - Instead of using GND and +V which can get corrupted with noise, you use -V and +V with wires usually wrapped around each other, thus canceling out noise.

| Other common terms | Name                        |
|--------------------|-----------------------------|
| ADC                | Analog to digital converter |
| DAC                | Digital to analog converter |
| PWM                | Pulse width modulation      |

- SPI
- CAN
- USB
- Either-CAT
- Other
	- Light(AM and FM)
	- Ti Calculators

<!-- TOC -->

- [UART - Universal Asynchronous Receiver/Transmitter](#uart---universal-asynchronous-receivertransmitter)
- [I2C - Inter Integrated Circuit](#i2c---inter-integrated-circuit)
- [SPI - Serial Peripheral Interface](#spi---serial-peripheral-interface)
- [Terms](#terms)
- [CAN - Controller area network](#can---controller-area-network)
- [Either CAT - Ethernet for control automation technology](#either-cat---ethernet-for-control-automation-technology)

<!-- /TOC -->


## [UART - Universal Asynchronous Receiver/Transmitter](./serial_communication.md)
Simple asynchronous serial communication that sends data one bit at a time(baud rate) over two wires.

| Wires | Name     |
|-------|----------|
| GND   | Ground   |
| TX    | Transmit |
| RX    | Receive  |

- TX from one device connects to the RX of the other device.

## [I2C - Inter Integrated Circuit](./serial_protocols.md)
A two wire serial communication protocol for connecting multiple devices using a shared clock and data line.

| Wires | Name              |
|-------|-------------------|
| GND   | Ground            |
| SDA   | Serial data line  |
| SCL   | Serial clock line |

- The master controls the clock and initiates the communication.
- Each device requires a 7 or 10 bit address.

## [SPI - Serial Peripheral Interface](./serial_protocols.md)

| Wires | Name |
|-|-|
| 

- Ports
	- CS - Chip select
	- SCK - Serial clock signal
	- MOSI - Master out slave in. Master pin is TX.
	- MISO - Master in slave out. Master pin is RX.
- QSPI - Quad SPI. 2 MOSI and MISO.


## Terms






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