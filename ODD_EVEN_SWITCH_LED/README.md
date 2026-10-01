# Even & Odd LED Control Using Switches

This project demonstrates **Even and Odd LED control using the PIC16F877A microcontroller**. Two switches are used to control two different LED patterns connected to PORTB.

## Components Used

* PIC16F877A Microcontroller
* 8 LEDs
* 2 Push Buttons / Switches
* Proteus 8
* MPLAB IDE

## Software Used

* MPLAB IDE
* Proteus 8 Professional

## Files

* `even_odd_led.c` → Embedded C source code
* `even_odd_led.png` → Proteus circuit
* `even_odd_led_output.png` → Output screenshot

## Working

The program continuously checks the two switches connected to **RD0** and **RD1**.

* **SW1 Pressed** → Even LED pattern is displayed using `0x55`.
* **SW2 Pressed** → Odd LED pattern is displayed using `0xAA`.
* **No Switch Pressed** → All LEDs are turned OFF.

### LED Patterns

**SW1 – Even LED Pattern**

```text
PORTB = 0x55
```

```text
LED8  LED7  LED6  LED5  LED4  LED3  LED2  LED1
 OFF   ON    OFF   ON    OFF   ON    OFF   ON
```

**SW2 – Odd LED Pattern**

```text
PORTB = 0xAA
```

```text
LED8  LED7  LED6  LED5  LED4  LED3  LED2  LED1
 ON   OFF    ON    OFF   ON    OFF   ON    OFF
```

## Pin Configuration

| PIC16F877A Pin | Function |
| -------------- | -------- |
| RB0–RB7        | 8 LEDs   |
| RD0            | SW1      |
| RD1            | SW2      |

## Control Logic

```text
SW1 Pressed → 0x55 → Even LED Pattern

SW2 Pressed → 0xAA → Odd LED Pattern

No Switch   → 0x00 → All LEDs OFF
```

This project helps to understand **switch interfacing, GPIO input/output control, hexadecimal bit patterns, LED interfacing, and Embedded C programming using the PIC16F877A microcontroller.**
