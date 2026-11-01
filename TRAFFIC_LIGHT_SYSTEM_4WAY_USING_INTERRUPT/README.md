# 🚦 4-Way Traffic Light Control System with Emergency Vehicle Priority using PIC16F877A

## 📌 Project Overview

This project implements a **4-Way Traffic Light Control System with Emergency Vehicle Priority** using the PIC16F877A microcontroller and Embedded C programming.

The system controls traffic signals across four different roads in a predefined sequence. It also provides priority access to emergency vehicles such as ambulances and fire engines using external interrupts and PORTB change interrupts.

The main objective is to manage normal traffic flow efficiently and provide a temporary green signal to the selected road during an emergency request.

## ⚙️ Project Features

### 1. Normal Traffic Operation
- Controls traffic signals for four different roads.
- Each road receives a Green signal for 5 seconds.
- The Green signal is followed by a Yellow signal for 2 seconds.
- Automatically switches to the next road after completing each sequence.
- Repeats the traffic sequence continuously.

### 2. Timer-Based Operation
- Uses Timer0 to generate periodic interrupts.
- Creates a 1-second time base using Timer0 overflow interrupts.
- Controls traffic signal timing without using software delay functions.
- Maintains consistent timing for normal and emergency operations.

### 3. Emergency Vehicle Detection Using Interrupts
- Uses External Interrupt (RB0/INT) for Road 1 emergency detection.
- Uses PORTB Change Interrupt (RB4, RB5 and RB6) for Roads 2, 3 and 4.
- Detects emergency requests through push buttons.
- Provides priority Green signal to the selected road for 10 seconds.
- Saves the current traffic signal state before entering emergency mode.
- Automatically restores the previous traffic sequence after emergency handling.

### 4. State Management
- Stores the current road number.
- Stores the current traffic signal phase.
- Saves the elapsed time of the current phase.
- Restores the saved traffic state after emergency operation.

## 🛠️ Hardware Requirements

- PIC16F877A Microcontroller
- 20 MHz Crystal Oscillator
- Red LEDs
- Yellow LEDs
- Green LEDs
- Current-Limiting Resistors
- Emergency Push Buttons
- Power Supply
- Connecting Wires

## 💻 Software Requirements

- MPLAB IDE
- HI-TECH C Compiler
- Proteus Design Suite

## 🔌 Pin Configuration

### Traffic Light LED Connections

| Road | Red LED | Yellow LED | Green LED |
|---|---|---|---|
| Road 1 | RD0 | RD1 | RD2 |
| Road 2 | RD3 | RD4 | RD5 |
| Road 3 | RD6 | RD7 | RC0 |
| Road 4 | RC1 | RC2 | RC3 |

### Emergency Button Connections

| Road | PIC Pin | Interrupt Type |
|---|---|---|
| Road 1 | RB0/INT | External Interrupt |
| Road 2 | RB4 | PORTB Change Interrupt |
| Road 3 | RB5 | PORTB Change Interrupt |
| Road 4 | RB6 | PORTB Change Interrupt |

**Note:** Emergency inputs are active LOW. The corresponding input pin is pulled LOW when the emergency button is pressed.

## ⏱️ Timer0 Configuration

- Microcontroller Clock: 20 MHz
- Timer: Timer0
- Timer0 Preload Value: 236
- Prescaler: 1:256
- Timer Interrupt: Overflow Interrupt
- Time Base: Approximately 1 second

Timer0 overflow interrupts are counted to generate the time base used by the traffic light control system.

## 🔄 Working Principle

**Normal Mode:**

1. Road 1 receives a Green signal for 5 seconds.
2. Road 1 changes to Yellow for 2 seconds.
3. Road 2 receives a Green signal.
4. The same sequence continues for Roads 3 and 4.
5. After Road 4, the sequence returns to Road 1.

**Emergency Mode:**

1. An emergency button is pressed.
2. The corresponding interrupt detects the emergency request.
3. The current traffic signal state is saved.
4. The selected road immediately receives priority Green signal when the main loop processes the request.
5. The emergency Green signal remains active for 10 seconds.
6. The controller restores the previously saved traffic state.
7. Normal traffic operation continues.

## 🧪 Proteus Simulation Procedure

1. Create a new project in Proteus.
2. Add the PIC16F877A microcontroller.
3. Connect the 20 MHz crystal oscillator.
4. Connect the traffic signal LEDs according to the pin configuration.
5. Connect emergency push buttons to RB0, RB4, RB5 and RB6.
6. Write and compile the Embedded C program in MPLAB IDE.
7. Load the generated HEX file into the PIC16F877A.
8. Set the clock frequency to 20 MHz.
9. Start the Proteus simulation.
10. Test normal traffic sequencing and emergency button operations.

## 🎯 Expected Output

- Automatic four-road traffic signal operation.
- Green signal for 5 seconds.
- Yellow signal for 2 seconds.
- Emergency priority Green signal for 10 seconds.
- Automatic restoration of the previously saved traffic state.

## 📚 Learning Outcomes

Through this project, I gained practical knowledge of:

- PIC16F877A microcontroller programming.
- Embedded C programming.
- Timer0 configuration and overflow interrupts.
- External Interrupt handling.
- PORTB Change Interrupt handling.
- Real-time event detection.
- Traffic signal sequencing.
- Interrupt-based application development.
- State saving and restoration.
- Proteus simulation and debugging.

## 🚀 Technologies Used

- **Microcontroller:** PIC16F877A
- **Programming Language:** Embedded C
- **IDE:** MPLAB IDE (HI-TECH C)
- **Simulation:** Proteus
- **Clock Frequency:** 20 MHz
- **Peripherals:** Timer0, External Interrupt, PORTB Change Interrupt

## 👨‍💻 Author

**Abilash S.**

Embedded Systems Engineer | Embedded C | PIC Microcontrollers | Hardware Interfacing

---

⭐ If you find this project interesting, feel free to star this repository!

**Learning by Doing | Building Real-Time Embedded Applications**