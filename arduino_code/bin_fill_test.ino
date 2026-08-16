// Smart Dustbin
// Step 10 - Bin Fill Percentage Test

// Ultrasonic Sensor 2
const int TRIG_PIN = 4;
const int ECHO_PIN = 5;

// Height of the bin in centimeters
const float BIN_HEIGHT = 40.0;


// Function to measure distance
float readDistance()
{
  // Make sure trigger starts LOW
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send ultrasonic trigger pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure echo response
  unsigned long duration = pulseIn(ECHO_PIN, HIGH);

  // Convert time to centimeters
  float distance = duration / 58.0;

  return distance;
}


// Function to calculate bin fill percentage
float calculateFillPercentage(float distance)
{
  float fillLevel = BIN_HEIGHT - distance;

  float fillPercentage =
      (fillLevel / BIN_HEIGHT) * 100.0;

  // Prevent percentage from going below 0
  if (fillPercentage < 0)
  {
    fillPercentage = 0;
  }

  // Prevent percentage from going above 100
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

  Serial.println("Bin Fill Level Test Started");
}


void loop()
{
  // Read distance from Sensor 2
  float distance = readDistance();

  // Calculate fill percentage
  float fillPercentage =
      calculateFillPercentage(distance);

  Serial.print("Waste Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Bin Fill Level: ");
  Serial.print(fillPercentage);
  Serial.println("%");

  Serial.println("----------------------");

  delay(1000);
}