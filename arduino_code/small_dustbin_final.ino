#include <Servo.h>

// =================================================
// PIN CONFIGURATION
// =================================================

// Sensor 1 - Hand/Object Detection
const int TRIG_SENSOR_1 = 2;
const int ECHO_SENSOR_1 = 3;

// Sensor 2 - Waste Level
const int TRIG_SENSOR_2 = 4;
const int ECHO_SENSOR_2 = 5;

// Outputs
const int GREEN_LED = 6;
const int RED_LED = 7;
const int BUZZER = 8;

// Servo
const int SERVO_PIN = 9;

Servo lidServo;


// =================================================
// SETTINGS
// =================================================

const float BIN_HEIGHT = 40.0;

const float FULL_THRESHOLD = 90.0;

const float OBJECT_THRESHOLD = 20.0;


// Servo positions
const int CLOSED_ANGLE = 0;
const int OPEN_ANGLE = 90;


// Lid timing
const unsigned long LID_OPEN_TIME = 3000;


// =================================================
// LID STATE
// =================================================

bool lidOpen = false;

unsigned long lidOpenedAt = 0;


// =================================================
// READ ULTRASONIC DISTANCE
// =================================================

float readDistance(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  unsigned long duration =
      pulseIn(echoPin, HIGH);

  float distance = duration / 58.0;

  return distance;
}


// =================================================
// CALCULATE BIN FILL
// =================================================

float calculateFillPercentage(float distance)
{
  float fillLevel =
      BIN_HEIGHT - distance;

  float fillPercentage =
      (fillLevel / BIN_HEIGHT) * 100.0;


  if (fillPercentage < 0)
  {
    fillPercentage = 0;
  }


  if (fillPercentage > 100)
  {
    fillPercentage = 100;
  }


  return fillPercentage;
}


// =================================================
// SETUP
// =================================================

void setup()
{
  Serial.begin(9600);


  // Sensor 1
  pinMode(TRIG_SENSOR_1, OUTPUT);
  pinMode(ECHO_SENSOR_1, INPUT);


  // Sensor 2
  pinMode(TRIG_SENSOR_2, OUTPUT);
  pinMode(ECHO_SENSOR_2, INPUT);


  // Outputs
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);


  // Servo
  lidServo.attach(SERVO_PIN);

  lidServo.write(CLOSED_ANGLE);


  // Initial status
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);


  Serial.println("================================");
  Serial.println("SMART DUSTBIN SYSTEM STARTED");
  Serial.println("================================");
}


// =================================================
// MAIN LOOP
// =================================================

void loop()
{
  // =================================================
  // 1. READ SENSOR 1
  // =================================================

  float objectDistance =
      readDistance(TRIG_SENSOR_1, ECHO_SENSOR_1);


  delay(50);


  // =================================================
  // 2. READ SENSOR 2
  // =================================================

  float wasteDistance =
      readDistance(TRIG_SENSOR_2, ECHO_SENSOR_2);


  // =================================================
  // 3. CALCULATE BIN LEVEL
  // =================================================

  float fillPercentage =
      calculateFillPercentage(wasteDistance);


  // =================================================
  // 4. DISPLAY SENSOR DATA
  // =================================================

  Serial.println();

  Serial.print("Object Distance: ");
  Serial.print(objectDistance);
  Serial.println(" cm");


  Serial.print("Waste Distance: ");
  Serial.print(wasteDistance);
  Serial.println(" cm");


  Serial.print("Bin Fill Level: ");
  Serial.print(fillPercentage);
  Serial.println("%");


  // =================================================
  // 5. AUTOMATIC LID CONTROL
  // =================================================

  // Object detected and lid currently closed
  if (!lidOpen &&
      objectDistance > 0 &&
      objectDistance <= OBJECT_THRESHOLD)
  {
    Serial.println("Object detected!");
    Serial.println("Opening lid...");


    lidServo.write(OPEN_ANGLE);

    lidOpen = true;

    lidOpenedAt = millis();
  }


  // Close lid after 3 seconds
  if (lidOpen &&
      millis() - lidOpenedAt >= LID_OPEN_TIME)
  {
    Serial.println("Closing lid...");


    lidServo.write(CLOSED_ANGLE);

    lidOpen = false;

    Serial.println("Lid closed.");
  }


  // =================================================
  // 6. BIN STATUS
  // =================================================

  if (fillPercentage >= FULL_THRESHOLD)
  {
    // Full bin

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);


    Serial.println("WARNING: BIN IS FULL!");
    Serial.println("Red LED: ON");
    Serial.println("Buzzer: ON");
  }

  else
  {
    // Normal bin

    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);


    Serial.println("Bin Status: NORMAL");
    Serial.println("Green LED: ON");
  }


  Serial.println("-------------------------------");


  delay(300);
}