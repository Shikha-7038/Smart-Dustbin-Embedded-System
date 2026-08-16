// Smart Dustbin
// Step 9 - Two Ultrasonic Sensor Test

// Sensor 1 - Hand/Object Detection
const int TRIG_SENSOR_1 = 2;
const int ECHO_SENSOR_1 = 3;

// Sensor 2 - Waste Level Detection
const int TRIG_SENSOR_2 = 4;
const int ECHO_SENSOR_2 = 5;


// Function to measure distance
float readDistance(int trigPin, int echoPin)
{
  // Make sure trigger is LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send 10 microsecond trigger pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo response time
  unsigned long duration = pulseIn(echoPin, HIGH);

  // Convert time to distance in centimeters
  float distance = duration / 58.0;

  return distance;
}


void setup()
{
  Serial.begin(9600);

  // Sensor 1
  pinMode(TRIG_SENSOR_1, OUTPUT);
  pinMode(ECHO_SENSOR_1, INPUT);

  // Sensor 2
  pinMode(TRIG_SENSOR_2, OUTPUT);
  pinMode(ECHO_SENSOR_2, INPUT);

  Serial.println("Two Ultrasonic Sensor Test Started");
}


void loop()
{
  // Read Sensor 1
  float distance1 = readDistance(
    TRIG_SENSOR_1,
    ECHO_SENSOR_1
  );

  // Small delay between sensors
  delay(50);

  // Read Sensor 2
  float distance2 = readDistance(
    TRIG_SENSOR_2,
    ECHO_SENSOR_2
  );


  // Display Sensor 1 result
  Serial.print("Sensor 1 Distance: ");
  Serial.print(distance1);
  Serial.println(" cm");


  // Display Sensor 2 result
  Serial.print("Sensor 2 Distance: ");
  Serial.print(distance2);
  Serial.println(" cm");


  Serial.println("----------------------");

  delay(500);
}