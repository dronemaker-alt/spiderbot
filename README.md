# SpiderBot

SpiderBot is the working repository for the custom 8-DOF walking robot project based on the QuadBot-E / spider-style chassis concept.

The current baseline assumes:

- ESP8266 NodeMCU or ESP32 controller
- PCA9685 16-channel PWM servo driver
- 8 servos total: 2 joints per leg, 4 legs
- Optional OLED display, status LEDs, IMU, range sensor, and remote-control input
- Arduino-first firmware with room to migrate to PlatformIO later

## Project goals

1. Replace stock demo behavior with readable custom firmware.
2. Build reliable leg calibration and neutral-position storage.
3. Create simple gait primitives first: stand, crouch, wave, crawl, turn.
4. Add sensors and remote commands only after the servo geometry is repeatable.
5. Keep hardware notes, pin maps, and build decisions in the repo so the project does not get lost in chat history.

## Repository layout

```text
firmware/
  arduino/
    spiderbot_esp_pca9685/   Main Arduino sketch

docs/
  project-overview.md
  hardware-baseline.md
  pin-map.md
  gait-notes.md
  calibration.md
  roadmap.md

mechanical/
  README.md

electronics/
  README.md
```

## Current firmware status

The starter sketch initializes the PCA9685, defines 8 servo channels, centers the robot, and provides early gait helper functions. Servo pulse limits are placeholders and must be tuned per servo/linkage.

## Safety notes

Power the servos from a separate 5-6 V supply sized for stall current. Do not power the servo rail from the ESP board USB port. Remove legs or lift the robot during first motion tests.

## Next build checkpoint

- Confirm servo channel order.
- Set each leg to mechanical neutral.
- Tune `SERVOMIN`, `SERVOMAX`, and center offsets.
- Verify all joints move in the intended direction before gait testing.
