# Pin Map

## ESP32 + PCA9685 baseline

| Function | ESP32 Pin |
|---|---|
| SDA | GPIO21 |
| SCL | GPIO22 |
| OLED SDA | GPIO21 |
| OLED SCL | GPIO22 |
| Status LED | GPIO2 |

## PCA9685 servo assignment

| Channel | Leg | Joint |
|---|---|---|
| 0 | Front Left | Hip |
| 1 | Front Left | Knee |
| 2 | Front Right | Hip |
| 3 | Front Right | Knee |
| 4 | Rear Left | Hip |
| 5 | Rear Left | Knee |
| 6 | Rear Right | Hip |
| 7 | Rear Right | Knee |

## Notes

Servo directions may need inversion depending on linkage geometry.

Keep a notebook of:

- mechanical neutral angle
- minimum safe angle
- maximum safe angle
- linkage interference points
