# Human Interface ALU
HI-ALU is a bare-metal embedded system built on the RP2040 that enables interactive entry and processing of binary operands using physical buttons and LED register visualization. The system supports addition and subtraction operations, overflow detection, auditory feedback, and modular firmware architecture implemented fully in C without high-level abstractions.

---

### System Overview
The Human Interface ALU (HI-ALU) is an interactive arithmetic processing unit designed and implemented using bare-metal C firmware on the RP2040 microcontroller. The system simulates an 8-bit shift register for operand entry through tactile buttons, providing real-time LED visualization of binary values.

Users select arithmetic operations via dedicated hardware controls, after which a modular Arithmetic Logic Unit (ALU) firmware module performs addition or subtraction on the stored operands. The result is displayed on the LED register, while overflow conditions are flagged using a dedicated status indicator.

The firmware architecture follows a structured modular design consisting of GPIO drivers, input handling, register management, ALU computation logic, buzzer feedback control, and a finite state machine governing system operation. This project demonstrates low-level hardware interfacing, embedded UI design, arithmetic flag handling, and real-time system control without reliance on high-level frameworks.

---

### Repository Structure:
.<br>
```
binary-adder/
│
├── src/
│   ├── main.c
│   ├── state_machine.c
│   ├── register.c
│   ├── alu.c
│   ├── buttons.c
│   ├── buzzer.c
│   └── gpio_driver.c
│
├── inc/
│   ├── state_machine.h
│   ├── register.h
│   ├── alu.h
│   ├── buttons.h
│   ├── buzzer.h
│   └── gpio_driver.h
│
├── docs/
│   ├── architecture.png
│   ├── state_flow.png
│   └── wiring.png
│
└── README.md
```
---

### Features:
- 8-bit shift register operand entry
- Addition and subtraction modes
- Overflow detection indicator
- Status LEDs for operation selection
- Piezo buzzer feedback
- Modular bare-metal C firmware architecture

---

### System Operations

![conceptual diagram](</docs/system_conceptual_flow.png>)

---

### Hardware:
- RP2040 Microcontroller
- 8 Red LEDs (Binary Register)
- Operation Status LEDs
- Pushbuttons (Operand Input & Control)
- Piezo Buzzer

---

### System Flow Diagram
![system flow diagram](</docs/system_flow.png>)

---

