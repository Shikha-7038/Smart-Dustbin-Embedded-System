# Wokwi Simulation

## Project

Smart Dustbin – Industry-Oriented Embedded System

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

## Functions Demonstrated

The simulation demonstrates:

1. Automatic object detection
2. Automatic lid opening
3. Automatic lid closing
4. Waste-level measurement
5. Fill percentage calculation
6. Green LED normal-status indication
7. Red LED full-bin indication
8. Buzzer alert
9. Serial Monitor output

## Test Conditions

### Object Detection

Sensor 1:

15 cm

Expected result:

- Object detected
- Servo opens the lid
- Lid closes after the configured delay

### Empty Bin

Sensor 2:

40 cm

Expected result:

- Approximately 0% full
- Green LED ON
- Red LED OFF
- Buzzer OFF

### Half-Full Bin

Sensor 2:

20 cm

Expected result:

- Approximately 50% full
- Green LED ON
- Red LED OFF
- Buzzer OFF

### Full Bin

Sensor 2:

4 cm

Expected result:

- Approximately 90% full
- Red LED ON
- Buzzer ON
- Green LED OFF

## Simulation Link

Wokwi Project:

https://wokwi.com/projects/472541018126512129