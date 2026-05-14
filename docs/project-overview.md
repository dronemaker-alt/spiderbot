# Project Overview

SpiderBot is a custom quadruped / spider robot platform intended as a flexible robotics testbed.

The design direction mixes:

- simple hobby servo mechanics
- ESP-based embedded control
- modular sensor expansion
- future AI-assisted interaction
- portable field diagnostics concepts

## Baseline hardware

### Controller options

- ESP8266 NodeMCU
- ESP32 DevKit
- LilyGo T-P4 (future migration target)

### Motion system

- PCA9685 servo controller
- 8 DOF minimum
- Standard hobby servos or metal gear servos

### Future expansion

- IMU stabilization
- camera module
- OLED status display
- battery telemetry
- wireless control
- autonomous navigation experiments

## Design philosophy

Readable firmware first.

The goal is not only making the robot move, but understanding:

- gait timing
- inverse kinematics basics
- power behavior
- embedded state machines
- sensor fusion
- modular robotics architecture
