[Home](../README.md#embedded-programming)

# Serial Protocols
The purpose of serial communication is to transfer information between devices while using fewer wires than parallel communication.

- **Synchronous/Asynchronous** - Uses a clock signal/Doesn't use a clock signal.
- **Half-duplex/Full-duplex** - Only one device can send and receive data/Both devices can send and receive data at the same time.
- **Differential** - Instead of using GND and +V which can get corrupted with noise, you use -V and +V with wires usually wrapped around each other, thus canceling out noise.

| Other common terms | Name                        |
|--------------------|-----------------------------|
| ADC                | Analog to digital converter |
| DAC                | Digital to analog converter |
| PWM                | Pulse width modulation      |

| Protocol Names | Speed     | Distance | Communication style    | Wires | Sync/Aysnc | Half/Full |
|----------------|-----------|----------|------------------------|-------|------------|-----------|
| UART           | Low       | Short    | Either device can send | 2-3   | Async      | Half      |
| I2C            | Low       | Short    | Master multi-slave     | 3     | Sync       | Half      |
| SPI            | High      | Short    | Master multi-slave     | 4-5   | Sync       | Full      |
| CAN            | Medium    | Medium   | Network                | 2     | Async      | Half      |
| USB            | High      | Short    | Master-slave           | 4     | Sync       | Full      |
| EtherCAT       | Very high | Medium   | Network                | 8     | Sync       | Full      |

<!-- TOC -->

- [UART - Universal Asynchronous Receiver/Transmitter](#uart---universal-asynchronous-receivertransmitter)
- [I2C - Inter Integrated Circuit](#i2c---inter-integrated-circuit)
- [SPI - Serial Peripheral Interface](#spi---serial-peripheral-interface)
- [CAN - Controller Area Network](#can---controller-area-network)
- [USB - Universal Serial Bus](#usb---universal-serial-bus)
- [EtherCAT - Ethernet for Control Automation Technology](#ethercat---ethernet-for-control-automation-technology)

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
Full duplex synchronous serial protocol where a master communicates with one or more slaves using separate lines for data in, data out, clock, and chip select.

| Wires | Name                |
|-------|---------------------|
| GND   | Ground              |
| CS    | Chip select         |
| SCK   | Serial clock signal |
| MOSI  | Master out slave in |
| MISO  | Master in slave out |

## [CAN - Controller Area Network](./serial_protocols.md)
CAN is a network serial protocol, not a master slave one. It is half duplex, asynchronous, differential pairs, and has error correction(CRC).

| Wires | Name     |
|-------|----------|
| CANH  | CAN High |
| CANL  | CAN Low  |

- An ID is sent with the data, only the device with the ID processes the data.
	- Devices don't know which device sent the data.
- All nodes must agree upon a baud rate.

## [USB - Universal Serial Bus](./serial_protocols.md)
USB is a serial protocol that allows devices to connect and exchange info with a host using high speed differential bus.

| Wires | Name          |
|-------|---------------|
| VBUS  | 5v power      |
| GND   | Ground        |
| D+    | Data positive |
| D-    | Data negative |

## [EtherCAT - Ethernet for Control Automation Technology](./serial_protocols.md)
EtherCAT is a high performance real time ethernet based serial protocol for industrial automation.

- 4 twisted pairs of TX and RX wires.