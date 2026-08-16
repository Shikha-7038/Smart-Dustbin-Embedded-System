// Smart Dustbin
// Step 12 - Automatic Lid Control

#include <Servo.h>

// -------------------------
// Ultrasonic Sensor 1
// -------------------------

const int TRIG_PIN = 2;
const int ECHO_PIN = 3;


// -------------------------
// Servo
// -------------------------

const int SERVO_PIN = 9;

Servo lidServo;


// -------------------------
// Lid settings
// -------------------------

const int CLOSED_ANGLE = 0;
const int OPEN_ANGLE = 90;


// Object detection threshold
const float DETECTION_DISTANCE = 20.0;


// -------------------------
// Function to read distance
// -------------------------

float readDistance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration =
      pulseIn(ECHO_PIN, HIGH);

  float distance = duration / 58.0;

  return distance;
}


// -------------------------
// Setup
// -------------------------

void setup()
{
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lidServo.attach(SERVO_PIN);

  // Start with lid closed
  lidServo.write(CLOSED_ANGLE);

  Serial.println("Automatic Lid System Started");
}


// -------------------------
// Main program
// -------------------------

void loop()
{
  float distance = readDistance();

  Serial.print("Object Distance: ");
  Serial.print(distance);
  Serial.println(" cm");


  // Check whether an object is close
  if (distance <= DETECTION_DISTANCE)
  {
    Serial.println("Object detected!");
    Serial.println("Opening lid...");

    // Open lid
    lidServo.write(OPEN_ANGLE);

    delay(3000);

    // Close lid
    lidServo.write(CLOSED_ANGLE);

    Serial.println("Lid closed.");

    delay(1000);
  }
  else
  {
    Serial.println("No object detected.");
    Serial.println("Lid remains closed.");

    // Make sure lid stays closed
    lidServo.write(CLOSED_ANGLE);
  }

  Serial.println("----------------------");

  delay(500);
}