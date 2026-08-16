// Smart Dustbin
// Step 11 - Servo Motor Test

#include <Servo.h>

Servo lidServo;

const int SERVO_PIN = 9;

void setup()
{
  lidServo.attach(SERVO_PIN);

  // Start with lid closed
  lidServo.write(0);

  delay(1000);
}

void loop()
{
  // Open lid
  lidServo.write(90);

  delay(3000);

  // Close lid
  lidServo.write(0);

  delay(3000);
}