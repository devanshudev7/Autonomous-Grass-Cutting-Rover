# 🚜 Autonomous Grass-Cutting & Weedicide Rover

> **A smart, self-navigating utility rover built with an ATmega328P, HC-SR04 sensor, and L298N motor driver. It features dynamic obstacle avoidance, a safety-interlocked grass cutter, and an automated 12V weedicide pump.**

This repository contains the firmware and hardware architecture for a prototype automated terrain maintenance robot. Operating in a continuous feedback loop of sensing, deciding, and acting, this rover is designed to safely and efficiently maintain grassy terrains without human intervention. 

---

## ✨ Key Highlights

* **Dynamic Obstacle Avoidance:** Utilizes HC-SR04 ultrasonic distance sensing to detect and navigate around environmental hazards in real-time.
* **Safety-Interlocked Cutter:** Features a relay-switched, high-speed cutting motor equipped with a forward-motion safety lock to ensure safe and predictable operation.
* **Automated Fluid Distribution:** Integrates an independent 12V fluid pump to manage automated weedicide and chemical distribution along its path.
* **Robust Hardware Stack:** Driven by an ATmega328P microcontroller and an L298N motor driver for precise locomotion and actuation.

---

## 🛠️ System Architecture & Engineering

This project goes beyond basic robotics to showcase practical, real-world applications of several core engineering concepts:

* **Embedded Systems Design:** Writing efficient, non-blocking firmware for continuous sensory polling and motor control.
* **Sensor Fusion & Logic:** Translating raw ultrasonic echo data into immediate navigational decisions.
* **Power Rail Management:** Safely isolating the power requirements of the logic board (ATmega328P), high-current cutting motors, and the 12V fluid pump.

---

## 📄 Documentation & Resources

For a deep dive into the system architecture, power rail schematics, and mechanical design considerations, please refer to our complete Technical Report attached in this repository:

* 📎 **[Technical Report](https://github.com/devanshudev7/Autonomous-Grass-Cutting-Rover/blob/850ba8cbca28d08eecf3bcbd05fcc4e048bdee91/Technical%20Report.pdf)**
