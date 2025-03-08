[Home](../README.md)

# STM32
- STM32-Nucleo-64-F446RE

- STM32 is a Cortex-M4 ARMv7-M based micro-controller.
- Cortexes
	- Cortex-A(Application) - In most mobile devices.
	- Cortex-M(eMbedded) - Designed for the low cost embedded market.
	- Cortex-R(Real Time) - High performance embedded systems.

## Why use STM32s over other micro-controllers?
- STM32 micro-controllers offer many different forms from low power to high performance for cheap and produced at scale.
	- You can often port the same code from one STM32 to another.
- It is popular so there's a lot of examples, tutorials, and ecosystem.

## Registers
- Registers
	- R0-R12 general purpose registers
	- R13 - Stack pointer
	- R14 - Link Register
	- R15 - Program counter
- FPU(Floating point unit) registers
	- S0-S15
	- S16-S31
	- FPSCR

## ARM asm
- When working with variables, you typically fetch(load variable into reg), modify, save(store the reg into variable).

| Commands      | Description |
|---------------|-------------|
| movs des, src |             |
| ldrb des, src |             |
| strb des, src |             |
| smulbb        |             |
| orr.w         |             |
| bic.w         |             |

- load and store - Transfer data between CPU registers and memory locations.

## Memory layout
- 0x0000 0000 - 0x1FFF FFFF Code Area
	- 0x0000 0000 - 0x0800 0000 - Aliased to flash, system memory, or SRAM
- 0x2000 0000 - 0x3FFF FFFF SRAM - Static RAM. Fast, but expensive.
- 0x4000 0000 - 0x5FFF FFFF Peripherals
- 0x6000 0000 - 0x9FFF FFFF External RAM




- Flash - Memory is saved even on power offs. This is where code is usually stored on micro-controllers.

- Memory layout or Cortex-M: Address space is 4GB wide
	- 512MB to code area
		- For stm32s
		- Option bytes
		- System memory
		- Reserved
		- Flash
		- Reserved
		- 
	- 512 MB to SRAM
		- Stack is usually here
	- 512 MB Peripherals
	- 1 GB External RAM

## Bit Banding
- Setting a bit to 1
	- temp |= 0x4;
- Setting a bit to 0
	- temp &= ~0x4;
- Toggling a bit
	- temp ^= 0x4;

- Maps a single bit to a memory address so that it cna be modified atomically.

## Installing
- `sudo apt install stlink-tools`
- `sudo apt install gcc-arm-none-eabi`

## Compiling
- `arm-none-eabi-gcc --specs=nosys.specs -std=gnu99 -g -O2 -Wall -mlittle-endian -mthumb -mthumb-interwork -mcpu=cortex-m0 -fsingle-precision-constant -Wdouble-promotion main.c -o main.elf`
- `arm-none-eabi-size -tA main.elf`
- `st-flash write main.bin 0x8000000`

## LED codes and pins
| ST-LINK LEDs          | Description                                               |
|-----------------------|-----------------------------------------------------------|
| Slow blinking Red/Off | Power on before USB initialization                        |
| Fast blinking Red/Off | After first correct communication between PC and ST-LIN K |
| Red On                | Init between PC and ST-LINK is complete                   |
| Green On              | Successful target communication initializtion             |
| Blinking Red/Green    | Communicating with the target                             |
| Orange On             | Communication failure                                     |


- LD2 - PA5(pin 32)

## GPIO ports
- Each port has 2 32-bit configuration registers, 2 32-bit data registers, a 32-bit set/reset register, a 16-bit reset register, and a 32-bit locking register.
	- 32-bit set/reset register - Allows atomic, updated in 1 step to avoid interruption in the middle, read and modify accesses to any of the GPIO registers.
	- Internal pull-up or pull-down resistors.
	- Protection diodes
	- Push/pull output driver - GPIO can output high or low voltage levels.
	- Output enable/disable
	- Schmitt-triggered digital input
	- Analog input
	- 3.3v in/out. Some pins are 5v tolerant.
	- Max current limit of 25mA per pin.
	- Input
		- Sampled into the Input Data Register every APB2 clock cycle.
	- Output
		- 

## Hardware Abstraction Layer(HAL)
- General purpose libraries across all STM32 micro-controllers.

HAL_Init()
SystemClock_Config()
MX_GPIO_Init()

GPIO_PIN_SET
GPIO_PIN_RESET

| Function name            | Description |
|--------------------------|-------------|
| HAL_GPIO_ReadPin         |             |
| HAL_GPIO_WritePin        |             |
| HAL_GPIO_TogglePin       |             |
| HAL_GPIO_LockPin         |             |
| HAL_GPIO_EXTI_IRQHandler |             |
| HAL_GPIO_EXTI_Callback   |             |