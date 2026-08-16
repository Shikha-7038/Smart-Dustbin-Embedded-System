// Smart Dustbin
// Step 13 - LED and Buzzer Alert Test

// Ultrasonic Sensor 2
const int TRIG_PIN = 4;
const int ECHO_PIN = 5;

// Output pins
const int GREEN_LED = 6;
const int RED_LED = 7;
const int BUZZER = 8;

// Bin settings
const float BIN_HEIGHT = 40.0;

// Full-bin threshold
const float FULL_THRESHOLD = 90.0;


// Read ultrasonic distance
float readDistance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH);

  float distance = duration / 58.0;

  return distance;
}


// Calculate fill percentage
float calculateFillPercentage(float distance)
{
  float fillLevel = BIN_HEIGHT - distance;

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


void setup()
{
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Start in normal state
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);

  Serial.println("Bin Alert System Started");
}


void loop()
{
  float distance = readDistance();

  float fillPercentage =
      calculateFillPercentage(distance);

  Serial.print("Waste Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Bin Fill Level: ");
  Serial.print(fillPercentage);
  Serial.println("%");


  // Check full-bin threshold
  if (fillPercentage >= FULL_THRESHOLD)
  {
    // Full bin
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);

    Serial.println("WARNING: BIN IS FULL!");
    Serial.println("Red LED ON");
    Serial.println("Buzzer ON");
  }
  else
  {
    // Normal bin
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);

    Serial.println("Bin status: NORMAL");
    Serial.println("Green LED ON");
  }

  Serial.println("----------------------");

  delay(1000);
}