[Home](../README.md#embedded-programming)

# STM32F411 Black Pill
- [HAL Documentation](https://www.st.com/resource/en/user_manual/um1725-description-of-stm32f4-hal-and-lowlayer-drivers-stmicroelectronics.pdf)
- [Reference manual](https://www.st.com/resource/en/reference_manual/rm0383-stm32f411xce-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)

![Pinout](./black_pill_pinout.png)

| Feature             | Specs                             |
|---------------------|-----------------------------------|
| CPU                 | Cortex-M4 100MHz                  |
| RAM                 | 128kB                             |
| Flash               | 512kB                             |
| GPIO                | 32                                |
| ADC                 | 12 bit                            |
| USB                 | 1.1 Host/Device                   |
| UART                | 3                                 |
| I2C                 | 3                                 |
| SPI                 | 5                                 |
| I2S                 | 2                                 |
| Current consumption | 26mA                              |
| 32-bit FPU          | Use `float`s instead of `double`s |

<!-- TOC -->

- [GPIO](#gpio)
- [PWM](#pwm)
- [UART](#uart)
- [I2C](#i2c)
- [SPI](#spi)
- [I2S](#i2s)
- [Timers](#timers)
- [Watchdog](#watchdog)
- [Power mods](#power-mods)
- [ADC and DAC](#adc-and-dac)
- [Interrupts](#interrupts)
- [USB](#usb)
	- [Serial output via USB-C](#serial-output-via-usb-c)
- [DMA](#dma)
- [Set up](#set-up)
- [Other](#other)
	- [Memory layout](#memory-layout)
	- [Libraries](#libraries)

<!-- /TOC -->

--------------------------------------------------------------------------------
`#include "stm32f4xx_hal.h"`

## [GPIO](#stm32f411-black-pill)
GPIO allows the software to turn on and off a pin and read high or low from a pin.

- CubeMX: GPIO_Output or GPIO_Input
- HAL
	- `void HAL_GPIO_WritePin(port, pin, pinState)`
	- `void HAL_GPIO_TogglePin(port, pin)`
	- `PinState HAL_GPIO_ReadPin(port, pin)`
- Arguments
	- port: `GPIOA`, `GPIOB`, `GPIOC`
	- pin: `GPIO_PIN_1`, `GPIO_PIN_2`, ...
	- pinState: `GPIO_PIN_SET`, `GPIO_PIN_RESET`

## [PWM](#stm32f411-black-pill)
PWM approzimates an analog voltage by quickly switching between a fixed high voltage and ground so the average over time is the desired analogy voltage.

- PWM has three variables
	- **Duty cycle** - Percentage of time the pin is on during the cycle.
	- **Resolution** - Number of possible duty cycle values.
	- **Frequency** - How many times the cycle repeats per second.

Microcontrollers use a timer that counts up to a set value, then resets to 0. This is one PWM cycle, consisting of a high phase and a low phase. When the timer count exceeds a compare vlaue, the output switches from high to low. Changing this compare value changes the duty cycle. Chaning the maximum count value changes the resolution. The frequency depends on the clock frequency and the resoltion, where high resoltion lowers the frequency.

Ex: Given a system clock cycle of 72MHz and 8-bit(0-255) resolution, what's teh frequency of the PWM?

$\frac{72,000,000 \text{ counts}}{1 \text{ sec}} * \frac{1 \text{ cycle}}{256 \text{ counts}} = 218,250 \text{ cycles per second}$

- CubeMX
	- Click Timers on the left
	- Select any general purpose timers: TIM2, TIM3, etc.
	- Clock Source: Internal Clock
	- Channel#: PWM Generation CH#
		- The channel changes which pin the PWM is outputed on.
	- Under Configuration, Parameter Settings
		- **Counter Period**: Max number the timer counts up to.
		- **Pulse**: The compare value to set the duty cycle. Has to be less than the counter period.
- HAL
	- `HAL_TIM_PWM_Start(htimPtr, channel);`
	- `__HAL_TIM_SET_COMPARE(htimPtr, channel, pulse);` - Changes the duty cycle.
- Arguments
	- htimPtr: Reference to the timer. `&htim1`, `&htim2`, ...
	- channel: `TIM_CHANNEL_1`, `TIM_CHANNEL_2`, ...
	- pulse: 0 to counter period.
- Advanced settings
	- Prescaler: The timer only increments after it has counted to the prescalar, it's used to slow down the timer.

## [UART](#stm32f411-black-pill)

- CubeMX
	- Under Connectivity: USART#
	- Mode: Asynchronous
	- Set Baud Rate
- HAL
	- `HAL_UART_Transmit(uart, bufferArr, size, timeout);`
	- `HAL_UART_Receive(uart, bufferArr, size, timeout);`
- Arguments
	- uart: `&huart1`, `&huart2`, etc.
	- bufferArr is an array of uint8_t
	- size is the number of bytes to transmit or receive(uint16_t). `sizeof(bufferArr) - 1`
	- timeout in milliseconds

## [I2C](#stm32f411-black-pill)

- CubeMX
	- Under Connectivity: I2C#
	- Set Primary slave address: Is your device's slave address if it's used as an I2C slave.
- HAL
	- `HAL_I2C_Mem_Write(hi2c, address, regAddress, I2C_MEMADD_SIZE_8BIT, buffer, size, timeout);`
		- Write to register on the I2C.
	- `HAL_I2C_Mem_Read(hi2c, address, regAddress, I2C_MEMADD_SIZE_8BIT, buffer, size, timeout);`
		- Read from register on the I2C.
	- `HAL_I2C_Master_Transmit(hi2c, address, buffer, size, timeout);`
		- Transmit info to I2C device
	- `HAL_I2C_Master_Receive(hi2c, address, buffer, size, timeout);`
		- Read from to I2C device
	- `HAL_I2C_Slave_Transmit(hi2c, buffer, size, timeout);`
	- `HAL_I2C_Slave_Receive(hi2c, buffer, size, timeout);`
- Arguments
	- hi2c: `&hi2c1`, `&hi2c2`, etc. of type I2C_HandleTypeDef
	- address is the address left shifted by 1 of typ uint8_t. `0x3C << 1`
	- regAddrss is the address for the register you want to write to or read from on the I2C device.
	- buffer is usually an array of uint8_t
	- size is the number of bytes to transmit or receive(uint16_t).
	- timeout in milliseconds

## [SPI](#stm32f411-black-pill)
## [I2S](#stm32f411-black-pill)

## [Timers](#stm32f411-black-pill)
- Timers - Each one controls certain pins. The channel sets which particular pin.
	- RTC - Low power real time clock.
	- TIM1 - Advanced control timer.
		- For precise PWM and motor control.
	- TIM2 and TIM5 - 32 bit general purpose timers.
	- TIM3 and TIM4 - 16 bit general purpose timers.
	- TIM9, TIM10, and TIM11 - 16 bit general purpose timers.
- CubeMX - Setting a general purpose timer with a specific frequency.
- HAL
	- `HAL_Delay(uint32_t ms);`
	- `HAL_GetTick()` - Return milliseconds(ms) since startup.
	- `HAL_TIM_Base_Start(htim);`
	- `HAL_TIM_Base_Stop(htim);`
	- ` __HAL_TIM_GET_COUNTER(htim);`
- Arguments

## [Watchdog](#stm32f411-black-pill)
- A watchdog timer - A timer that needs to be periodically refreshed within a time interval, otherwise it resets the device because it indivates the code is no longer runnign corrently.

- HAL
	- HAL_IWDG_Init(IWDG_HandleTypeDef *hiwdg)
	- HAL_IWDG_Start(IWDG_HandleTypeDef *hiwdg)
	- HAL_IWDG_Refresh(IWDG_HandleTypeDef *hiwdg) - Resets the watchdog timer to prevent a reset.

## [Power mods](#stm32f411-black-pill)
- Power modes
	- HAL_PWR_EnterSleepMode(Regulator, SLEEPEntry);
	- HAL_PWR_EnterStopMode(Regulator, STOPEntry);
	- HAL_PWR_EnterStandbyMode();

## [ADC and DAC](#stm32f411-black-pill)
## [Interrupts](#stm32f411-black-pill)
- NVIC, EXTI

`TIM2_IRQHandler` - is a special function name that matches the entry in the STM32 interrupt vector table for TIM2.
	- So when TIM2 throws an interupt event, this function is automatically called.

- `HAL_TIM_PWM_Start_IT(htim, Channel);`
	- Starts the interupts associated with the timer.
	- Need to Enable NVIC Settings: TIM# global interupt

## [USB](#stm32f411-black-pill)

### [Serial output via USB-C](#stm32f411-black-pill)
- This doesn't work well with I2C or other serial communicatoin timing!!!
	- Use SWO debugger instead.
- CubeMX
	- Under System Core: RCC
	- High Speed Clock (HSE): Crystal/Ceramic Resonator
	- Low Speed Clock (LSE): Crystal/Ceramic Resonator
	- Under Connectivity: USB_OTG_FS
	- Mode: Device_Only
	- Under Middleware and Software Packs: USB_DEVICE
	- Class For FS IP: Communication Device Class (Cirtual Port Com)
	- Select Clock Configuration tab
	- Resolve Clock Issues

```C++
// In my_main.h
#include "usbd_cdc_if.h"
#include <stdio.h>

// Wrapped in extern c
int _write(int file, char *ptr, int len);

// In my_main.cpp wrapped in extern c
int _write(int file, char *ptr, int len) {
	CDC_Transmit_FS((uint8_t*)ptr, len);
	return len;
}

// Usage example
printf("Hello world!\r\n"); // You need \r
```

- The pins for usb(PA12 and PA11) are automatically connected to the onboard usb-c connector.
- Make sure your usb-c cable supports data.
- `screen /dev/ttyACM0 115200` to see terminal output.
- Add this to CMakeLists.txt to enable floats(`%f`) in printf.

```
# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES LINK_FLAGS "-u _printf_float")
```

## [DMA](#stm32f411-black-pill)
Direct memory access.
- Allows a pin to directly set addresses.

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
	- Left side in vs code click Run and Debug icon
	- Under STM32CUBE DEVICES AND BOARDS at the bottom left
		- Click the little download icon
5. Setup your code
	1. Create My_Code folder at the root level of your project.

In my_main.h

```C
#include "stm32f4xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

// Example of a variable that's declared in main.c
extern TIM_HandleTypeDef htim2;

void myCode();

#ifdef __cplusplus
}
#endif
```

In my_main.cpp

```C
#include "my_main.h"

#ifdef __cplusplus
extern "C" {
#endif

void myCode(){
	while(true) {}
}

#ifdef __cplusplus
}
#endif
```

2. In Core/Src/main.c

```C
/* USER CODE BEGIN Includes */
#include "../../My_Code/my_main.h"
/* USER CODE END Includes */

// ...

/* USER CODE BEGIN WHILE */
myCode();
/* USER CODE END WHILE */
```

3. In CMakeLists.txt

```
file(GLOB MY_CODE_SOURCES My_Code/*.cpp)
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
	# Add user sources here
	${MY_CODE_SOURCES}
)
```

6. Compiling, Flashing, and Debugging
	- Top bar -> Run -> Start Debugging or Run Without Debugging
		- Select: STM32Cube: STLink GDB Server
	- If it's your first time, you'll have to accept the popups that show up in the bottom right.
	- If you add new .cpp files, you may have to delete build/ to ensure CMake adds it in.

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