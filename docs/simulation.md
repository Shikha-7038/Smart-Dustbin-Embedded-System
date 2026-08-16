# Smart Dustbin - Wokwi Simulation

## Simulation Platform

Wokwi

## Microcontroller

Arduino UNO

## Components

- Arduino UNO
- HC-SR04 Ultrasonic Sensor 1
- HC-SR04 Ultrasonic Sensor 2
- Servo Motor
- Green LED
- Red LED
- Buzzer

---

## Pin Configuration

| Component | Arduino Pin |
|---|---|
| Sensor 1 TRIG | D2 |
| Sensor 1 ECHO | D3 |
| Sensor 2 TRIG | D4 |
| Sensor 2 ECHO | D5 |
| Green LED | D6 |
| Red LED | D7 |
| Buzzer | D8 |
| Servo Signal | D9 |

---

## System Operation

### 1. Object Detection

Sensor 1 detects the distance of a hand or object approaching the dustbin.

If the detected object is within 20 cm:

```text
Object detected
       ↓
Servo rotates to 90°
       ↓
Lid opens
       ↓
Wait approximately 3 seconds
       ↓
Servo returns to 0°
       ↓
Lid closes
```

## 2. Waste-Level Detection

Sensor 2 measures the distance between the sensor and the waste.
The system calculates the bin fill percentage using:
Fill Level = Bin Height - Measured Distance


Fill Percentage =
(Fill Level / Bin Height) × 100

## 3. Full-Bin Alert

When the calculated fill level reaches 90% or more:

Red LED turns ON
Buzzer turns ON
Green LED turns OFF
Warning message appears in the Serial Monitor

## 4. Normal Bin

When the bin is below 90%:

Green LED turns ON
Red LED turns OFF
Buzzer remains OFF
Simulation Test Cases

# Empty Bin
Sensor 2 distance:
40 cm

Expected fill level:
0%

Result:
Green LED ON
Red LED OFF
Buzzer OFF

# Half-Full Bin
Sensor 2 distance:
20 cm

Expected fill level:
50%

Result:
Green LED ON
Red LED OFF
Buzzer OFF

# Full-Bin Alert
Sensor 2 distance:
4 cm

Expected fill level:
90%

Result:
Red LED ON
Buzzer ON
Green LED OFF

# Automatic Lid
Sensor 1 distance:
15 cm

Result:
Servo moves to approximately 90°
Lid opens
After approximately 3 seconds:
Lid closes

## Simulation Result
The complete Smart Dustbin system was successfully simulated.

The simulation demonstrated:

- Object detection
- Automatic lid operation
- Waste-level monitoring
- Fill percentage calculation
- Full-bin detection
- LED status indication
- Buzzer alert
- Integrated system operation