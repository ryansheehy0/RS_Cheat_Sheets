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

<!-- TOC -->

- [Set up](#set-up)
- [GPIO](#gpio)
- [PWM](#pwm)
- [UART, I2C, SPI, and I2S](#uart-i2c-spi-and-i2s)
- [Timers, watchdogs, and power modes](#timers-watchdogs-and-power-modes)
- [ADC and DAC](#adc-and-dac)
- [Interrupts](#interrupts)
- [DMA](#dma)
- [Other](#other)
	- [Memory layout](#memory-layout)
	- [Libraries](#libraries)

<!-- /TOC -->

## [Set up](#stm32f411-black-pill)
1. Install: [CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html) and STM32CubeIDE for Visual Studio Code(stmicroelectronics.stm32-vscode-extension).
2. Generate starter code for CubeMX
	1. File -> New Project
	2. Type in your Commercial part number: STM32F411CEU6
	3. Start project in the top right
	4. Pinout & Configuration
	5. Project manager
		- Project Name
		- Project Location
		- Toolchain/IDE: CMake
	6. GENERATE CODE in the top right
3. Wire ST-Link

| ST-Link Pin | Board Pin |
|-------------|-----------|
| GND         | GND       |
| 3.3v        | 3.3v      |
| SWDIO       | DIO       |
| SWCLK       | SCLK      |

4. If it's your first time using your ST-Link device, you'll need to upgrade its firmware.
	- Left side in vs code click Run and Debug
	- Under STM32CUBE DEVICES AND BOARDS at the bottom left
		- Click the little download icon
5. Setup your code
	1. Create My_Code folder at the root level of your project.

	```C
	// In my_main.h
	#ifdef __cplusplus
	extern "C" {
	#endif

	void myCode();

	#ifdef __cplusplus
	}
	#endif
	```

	```C
	// In my_main.cpp
	#include "my_main.h"
	#include "stm32f4xx_hal.h"

	#ifdef __cplusplus
	extern "C" {
	#endif

	void myCode(){
		// Init code
		while(true) {
			// Loop code
		}
	}

	#ifdef __cplusplus
	}
	#endif
	```

	3. In Core/Src/main.c

	```C
	#include "../../My_Code/my_main.h"

	// ...

  /* USER CODE BEGIN WHILE */
  myCode();
  /* USER CODE END WHILE */
	```

	4. In CMakeLists.txt

	```
	file(GLOB MY_CODE_SOURCES My_Code/*.cpp)
	target_sources(${CMAKE_PROJECT_NAME} PRIVATE
			# Add user sources here
			${MY_CODE_SOURCES}
	)
	```

6. Compiling, Flashing, and Debugging
	- Top bar -> Run -> Start Debugging or Run Without Debugging
	- If it's your first time, you'll have to accept the popups that show up in the bottom right.
	- If you add new .cpp files, you may have to delete build/ to ensure CMake adds it in.

## [GPIO](#stm32f411-black-pill)
GPIO allows the software to turn on and off a pin and read high or low from a pin.

- CubeMX: GPIO_Output or GPIO_Input
- HAL
	- `void HAL_GPIO_WritePin(Port, Pin, PinState)`
	- `void HAL_GPIO_TogglePin(Port, Pin)`
	- `PinState HAL_GPIO_ReadPin(Port, Pin)`
- Arguments
	- Port: `GPIOA`, `GPIOB`, `GPIOC`
	- Pin: `GPIO_PIN_1`, `GPIO_PIN_2`, ...
	- PinState: `GPIO_PIN_SET`, `GPIO_PIN_RESET`

## [PWM](#stm32f411-black-pill)
PWM approzimates an analog voltage by quickly switching between a fixed high voltage and ground so the average over time is the desired analogy voltage.

- PWM has three variables:
	- Duty cycle - Percentage of time the pin is on during the cycle.
	- Resolution - Number of possible duty cycle settings.
	- Frequency - How many times the cycle repeats per second.

- How microcontrollers 
	- Inverse corelation between resolution and frequency.

- How to set up in cubeMX
	- What each setting means

- Code you impliment yourself

## [UART, I2C, SPI, and I2S](#stm32f411-black-pill)

## [Timers, watchdogs, and power modes](#stm32f411-black-pill)

- `HAL_Delay(ms)`
- 
- millis(), micros()

- A watchdog timer - A timer that needs to be periodically refreshed within a time interval, otherwise it resets the device because it indivates the code is no longer runnign corrently.

## [ADC and DAC](#stm32f411-black-pill)
## [Interrupts](#stm32f411-black-pill)
- NVIC, EXTI

## [DMA](#stm32f411-black-pill)
Direct memory access.
- Allows a pin to directly set addresses.

## [Other](#stm32f411-black-pill)
### [Memory layout](#stm32f411-black-pill)

<img width=500 src="./stm_memory_layout.png">

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

### [Libraries](#stm32f411-black-pill)
- **CMSIS** - Collection of components for Arm Cortex-based microcontrollers.
	- API to the core registers.
	- DSP library - Optimized signal processing functions.
	- RTOS abstraction layer
	- DMA controller code - Transfers data between memory and peripherals without involvement of the CPU.