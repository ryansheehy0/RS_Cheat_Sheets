[Home](../README.md)

# STM32
- STM32 is a powerful ARM based microprocessor.
- This uses  STM32-Nucleo-64-F446RE

| ST-LINK LEDs           | Description                                              |
|                       -|                                                         -|
| Slow blinking Red/Off  | Power on before USB initialization                       |
| Fast blinking Red/Off  | After first correct communication between PC and ST-LIN K|
| Red On                 | Init between PC and ST-LINK is complete                  |
| Green On               | Successful target communication initializtion            |
| Blinking Red/Green     | Communicating with the target                            |
| Orange On              | Communication failure                                    |


- LD2 - PA5(pin 32)

- HAL(Hardware Abstraction Layer) library.


Install:
	- sudo apt install stlink-tools
	- sudo apt install gcc-arm-none-eabi
Commands:
	- arm-none-eabi-gcc --specs=nosys.specs -std=gnu99 -g -O2 -Wall -mlittle-endian -mthumb -mthumb-interwork -mcpu=cortex-m0 -fsingle-precision-constant -Wdouble-promotion main.c -o main.elf
	- arm-none-eabi-size -tA main.elf
	- st-flash write main.bin 0x8000000

## Different specifications

## Blink an LED
- `sudo apt install gcc-arm-none-eabi`

## How to debug
