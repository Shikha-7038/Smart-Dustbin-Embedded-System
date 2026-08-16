# Smart Dustbin - Test Results

## Project

Smart Dustbin – Industry-Oriented Embedded System

## Testing Environment

Simulation Platform: Wokwi
Microcontroller: Arduino UNO

---

## Test 1 – Empty Bin

### Input

Sensor 1 distance: 40 cm  
Sensor 2 distance: 40 cm

### Expected Result

- Bin fill level approximately 0%
- Green LED ON
- Red LED OFF
- Buzzer OFF
- Lid remains closed

### Actual Result

- Bin fill level: 0%
- Green LED: ON
- Red LED: OFF
- Buzzer: OFF
- Lid: Closed

### Status

PASS

---

## Test 2 – Hand/Object Detection

### Input

Sensor 1 distance: 15 cm  
Sensor 2 distance: 40 cm

### Expected Result

- Object detected
- Servo moves to approximately 90°
- Lid opens
- Lid remains open for approximately 3 seconds
- Lid closes automatically

### Actual Result

- Object detected
- Servo opened the lid
- Lid closed automatically after the delay

### Status

PASS

---

## Test 3 – Half-Full Bin

### Input

Sensor 1 distance: 40 cm  
Sensor 2 distance: 20 cm

### Expected Result

- Bin fill level approximately 50%
- Green LED ON
- Red LED OFF
- Buzzer OFF

### Actual Result

- Bin fill level: approximately 50%
- Green LED: ON
- Red LED: OFF
- Buzzer: OFF

### Status

PASS

---

## Test 4 – Full Bin Alert

### Input

Sensor 1 distance: 40 cm  
Sensor 2 distance: 4 cm

### Expected Result

- Bin fill level approximately 90%
- Green LED OFF
- Red LED ON
- Buzzer ON

### Actual Result

- Bin fill level: approximately 90%
- Green LED: OFF
- Red LED: ON
- Buzzer: ON

### Status

PASS

---

## Test 5 – Complete System

### Input

Sensor 1 distance: 15 cm  
Sensor 2 distance: 4 cm

### Expected Result

- Object detected
- Lid opens
- Bin reports approximately 90% full
- Red LED ON
- Buzzer ON
- Lid closes automatically

### Actual Result

- Object detected
- Lid opened
- Bin reported approximately 90% full
- Red LED ON
- Buzzer ON
- Lid closed automatically

### Status

PASS

---

## Overall Result

All major functional tests passed successfully in the Wokwi simulation.

The system successfully demonstrated:

- Automatic object detection
- Automatic lid control
- Waste-level monitoring
- Fill percentage calculation
- Full-bin detection
- LED status indication
- Buzzer alert
- Integrated system operation