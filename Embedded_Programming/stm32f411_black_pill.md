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

## Compiling and flashing
- Cross compiler prefix: arm-none-eabi-
- Cross compiler path: /usr/bin/

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