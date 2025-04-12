# DC-driver

# DC-driver

## Demo Video
[![Watch the video](https://img.youtube.com/vi/rn20zOGnw4M/0.jpg)](https://www.youtube.com/watch?v=rn20zOGnw4M)

## Project Description
This project is a DC motor driver system using the Atmega8 microcontroller. The system is designed to control a DC motor via PWM signals, display information on an LCD 1602 screen, and interact with push buttons.

## Directory Structure
- **Code_Atmega8/**: Contains source code and related files for microcontroller programming.
  - **L298N/**: Main source code for the motor driver.
    - `main.c`, `main.h`: Main program files.
    - `GPIO.c`, `GPIO.h`: Library for GPIO configuration and control.
    - `PWM.c`, `PWM.h`: Library for PWM control.
    - `LCD_1602.c`, `LCD_1602.h`: Library for controlling the LCD 1602 display.
    - `EXTI.c`, `EXTI.h`: Library for external interrupt handling.
    - **Debug/**: Contains debugging-related files.
- **PCB/**: Contains PCB design files and schematics.
  - `PCB1.PcbDoc`: PCB design file.
  - `Sheet2.SchDoc`: Schematic file.
  - **__Previews/**: Contains previews of schematics.
  - **History/**: Version history of PCB designs.
  - **Project Logs for PCB_Project - Copy/**: Logs for the PCB project.

## Key Features
- Control DC motors using the L298N motor driver module.
- Display system status on an LCD 1602 screen.
- Adjust motor speed using PWM signals.
- Support for operations such as start, stop, accelerate, and decelerate.
- Interact with push buttons to change motor state and direction.

## Hardware Requirements
- Atmega8 microcontroller.
- L298N motor driver module.
- LCD 1602 display.
- Push buttons and pull-up resistors.
- 5V and 12V power supplies.

## Usage Instructions
1. Connect the hardware according to the schematic in the `PCB/` directory.
2. Flash the program from `Code_Atmega8/L298N/` to the Atmega8 microcontroller.
3. Power up the system.
4. Use the push buttons to control the motor and observe the status on the LCD.

## Authors
- **Thien** - Student ID: 20216243
- **Dung** - Student ID: 20216065