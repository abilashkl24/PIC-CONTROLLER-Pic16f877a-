# DC Motor Forward & Reverse Control Using PIC16F877A

This project demonstrates **DC motor forward and reverse direction control using the PIC16F877A microcontroller**. Two switches are used to control the motor direction through the **L293D motor driver**.

## Components Used

* PIC16F877A Microcontroller
* L293D Motor Driver
* DC Motor
* 2 Push Buttons / Switches
* 20 MHz Crystal
* Proteus 8
* MPLAB IDE

## Software Used

* MPLAB IDE
* MPLAB XC8 Compiler
* Proteus 8 Professional

## Files

* `motor_forward_reverse.c` → Embedded C source code
* `motor_forward_reverse.png` → Proteus circuit
* `motor_forward_reverse_output.png` → Output screenshot

## Working

The program continuously monitors two switches connected to **RD0** and **RD1**.

* **SW1 Pressed** → Motor rotates Forward
* **SW2 Pressed** → Motor rotates Reverse
* **No Switch Pressed** → Motor Stops
* **Both Switches Pressed** → Motor Stops

## Motor Control Logic

```text
SW1 = 0, SW2 = 1 → Forward
SW1 = 1, SW2 = 0 → Reverse
SW1 = 1, SW2 = 1 → Stop
SW1 = 0, SW2 = 0 → Stop
```

## Pin Configuration

| PIC16F877A Pin | Function     |
| -------------- | ------------ |
| RD0            | SW1          |
| RD1            | SW2          |
| RB0            | L293D IN1    |
| RB1            | L293D IN2    |
| RB2            | L293D Enable |

## L293D Control

```text
IN1 = 1, IN2 = 0 → Forward
IN1 = 0, IN2 = 1 → Reverse
IN1 = 0, IN2 = 0 → Stop
EN1 = 1 → Motor Driver Enabled
```

## Project Flow

```text
Switches
   ↓
PIC16F877A
   ↓
L293D Motor Driver
   ↓
DC Motor
   ↓
Forward / Reverse / Stop
```

## Applications

* Robotics
* Industrial Automation
* Conveyor Systems
* DC Motor Control
* Embedded Control Systems

## Learning Outcome

This project helps to understand **switch interfacing, GPIO control, L293D motor driver interfacing, DC motor direction control, and Embedded C programming using PIC16F877A**.

## CIRCUIT IMAGE 
![IMAGE](<CIRCUIT IMAGE.png>)

## OUTPUT IMAGE 
![IMAGE](<OUTPUT IMAGE.png>)

## OUTPUT IMAGE 
![IMAGE](<OUTPUT IMAGE1.png>)