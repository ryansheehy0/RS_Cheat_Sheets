[Home](../README.md#embedded-programming)

# STM32F411 Black Pill
[HAL Documentation](https://www.st.com/resource/en/user_manual/um1725-description-of-stm32f4-hal-and-lowlayer-drivers-stmicroelectronics.pdf)

![Pinout](./black_pill_pinout.png)

| Feature             | Specs            |
|---------------------|------------------|
| CPU                 | Cortex-M4 100MHz |
| RAM                 | 128kB            |
| Flash               | 512kB            |
| GPIO                | 32               |
| ADC                 | 12 bit           |
| USB                 | 1.1 Host/Device  |
| UART                | 3                |
| I2C                 | 3                |
| SPI                 | 5                |
| I2S                 | 2                |
| Current consumption | 26mA             |

## Memory layout

![STM Memory Layout](./stm_memory_layout.png)

- Flash - Slow, permanant storage.
- SRAM - Fast, reset after power off.

| Memory      | Description                                           |
|-------------|-------------------------------------------------------|
| .isr_vector | Stores interrupt vectors and reset handler addresses. |
| .text       | Your code                                             |
| .rodata     | Read only constants and literals.                     |
| .data       | Initialized global and static variables.              |
| .bss        | Uninitialized global and static variables.            |

- Interrupt vectors - Pointer to functions that run when an interrupt happens.
- Reset handler - The function that is ran first after a reset to initialize the system before main().
	- .data is copied from flash to sram
	- .bss is zeroed

## Compiling and flashing
- Cross compiler prefix: arm-none-eabi-
- Cross compiler path: /usr/bin/

- **CMSIS** - Collection of components for Arm Cortex-based microcontrollers.
	- API to the core registers.
	- DSP library - Optimized signal processing functions.
	- RTOS abstraction layer
	- DMA controller code - Transfers data between memory and peripherals without involvement of the CPU.

## Debugging
## Timers, watchdogs, and power modes
## Flashing LED
```C++
while (true) {
	HAL_GPIO_WritePin(Port, Pin, )
	Ports:
		GPIOA
		GPIOB
		GPIOC
	Pins:
		GPIO_PIN_3
	True: GPIO_PIN_SET, HIGH, 1
	False: GPIO_PIN_RESET, LOW, 0
	
	HAL_GPIO_TogglePin(Port, Pin)
	HAL_Delay(ms);
}
```

## UART, I2C, and SPI
## PWM
## ADC and DAC
## Interrupts
## Documentation link, Specs, and Pin layout
## Compiling and flashing
## Debugging
## Timers, watchdogs, and power modes
## Flashing LED
## UART, I2C, and SPI
## PWM
## ADC and DAC
## Interrupts