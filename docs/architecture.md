<div align="center"> 📘 Human-Interface ALU (HI-ALU) — Architecture Note</div>

## 1. System Overview

The Human-Interface ALU (HI-ALU) is a bare-metal embedded arithmetic system built on the RP2040 microcontroller. The system allows users to enter two binary variables through pushbuttons, select an arithmetic operation, and visualize the computed result on an 8-bit LED register.

A finite state machine coordinates operand entry, operation selection, evaluation, and result display. Overflow conditions are detected and indicated through a dedicated status LED and auditory feedback.