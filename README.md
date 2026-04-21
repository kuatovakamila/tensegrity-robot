# Tensegrity Robot

> A self-balancing robot built on tensegrity principles — controlled via Arduino firmware.

📂 **Repository:** [github.com/kuatovakamila/tensegrity-robot](https://github.com/kuatovakamila/tensegrity-robot)

---

## Overview

This project implements the control firmware for a **tensegrity robot** — a class of robots whose structure is maintained through a continuous balance of tension and compression forces, rather than rigid joints. The result is a lightweight, compliant, and mechanically resilient robot capable of locomotion through controlled deformation of its structure.

The firmware is written in C++ for Arduino and handles motor actuation to drive movement and maintain structural integrity.

---

## What is Tensegrity?

Tensegrity (portmanteau of *tension* + *integrity*) is a structural principle where rigid elements (rods/struts) are held in place entirely by a network of tensioned cables — none of the rigid parts touch each other. When applied to robotics, this creates structures that are:

- **Lightweight** — minimal rigid material
- **Shock-absorbing** — flexible under impact
- **Compliant** — adaptable to uneven terrain
- **Bio-inspired** — similar to how muscles and bones interact in living organisms

---

## Hardware

| Component | Description |
|-----------|-------------|
| Microcontroller | Arduino (Uno / Nano / Mega) |
| Actuators | Servo motors / DC motors |
| Structure | Rigid rods + elastic cables |
| Power | Battery pack |

> *(Update with your exact components)*

---

## Firmware

The control logic is implemented in `123.ino` — an Arduino sketch that manages:

- **Motor sequencing** — coordinated actuation to produce rolling/locomotion
- **Timing control** — precise pulse control for servo positioning
- **Movement patterns** — predefined gaits or actuation sequences for directional movement

---

## Tech Stack

| Layer | Technology |
|-------|------------|
| Firmware | C++ (Arduino) |
| IDE | Arduino IDE |
| Hardware Platform | Arduino |
| Actuation | PWM servo/motor control |

---

## Getting Started

### Prerequisites
- [Arduino IDE](https://www.arduino.cc/en/software) installed
- Required libraries installed via Arduino Library Manager

### Upload Firmware

```bash
# 1. Clone the repository
git clone https://github.com/kuatovakamila/tensegrity-robot.git

# 2. Open in Arduino IDE
File → Open → 123.ino

# 3. Select your board and port
Tools → Board → [Your Arduino Board]
Tools → Port → [Your COM Port]

# 4. Upload
Sketch → Upload
```

---

## References

- [NASA Tensegrity Robotics — Super Ball Bot](https://www.nasa.gov/technology/tensegrity-robots/)
- [Tensegrity — Wikipedia](https://en.wikipedia.org/wiki/Tensegrity)

---

## License

This project is open source and available under the [MIT License](LICENSE).
