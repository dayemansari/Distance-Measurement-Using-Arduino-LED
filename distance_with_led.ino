const int trigPin = 3;
const int echoPin = 2;

int redPin = 11;
int bluePin = 9;
int greenPin = 10;
int motorPin = 8;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  digitalWrite(motorPin, LOW);

  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Calculate duration and distance
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);  // Reduce delay for better response time

  // Condition: Distance <= 10 cm (Close distance, Red LED)
  if (distance <= 10) {
    digitalWrite(redPin, HIGH);
    delay(500);  // Short delay for quick blinking
    digitalWrite(redPin, LOW);
  }
  // Condition: Distance between 10 cm and 30 cm (Medium distance, Blue LED)
  else if (distance > 10 && distance <= 30) {
    digitalWrite(bluePin, HIGH);
    delay(1000);  // Shorter delay for more frequent checking
    digitalWrite(bluePin, LOW);
  }
  // Condition: Distance > 30 cm (Far distance, Green LED)
  else {
    digitalWrite(greenPin, HIGH);
  }

  // Turn off LEDs if distance condition changes
  if (distance > 10) {
    digitalWrite(redPin, LOW);
  }
  if (distance <= 10 || distance > 30) {
    digitalWrite(bluePin, LOW);
  }
  if (distance <= 30) {
    digitalWrite(greenPin, LOW);
  }
}
