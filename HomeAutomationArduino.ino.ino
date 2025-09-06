#define TRIG_PIN 5    // Trig pin of HC-SR04 (D5)
#define ECHO_PIN 18   // Echo pin of HC-SR04 (D18)
#define LED_PIN 2     // Onboard LED pin (GPIO 2)
#define LIGHT1 23     // Onboard LED pin (GPIO 2)
#define LIGHT2 13    // Onboard LED pin (GPIO 2)
#define LIGHT3 14    // Onboard LED pin (GPIO 2)
#define LIGHT4 12    // Onboard LED pin (GPIO 2)




void setup() {
  Serial.begin(115200); // Start Serial Monitor
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT); // Set LED as an output
  pinMode(LIGHT1, OUTPUT);
  pinMode(LIGHT2, OUTPUT);
  pinMode(LIGHT3, OUTPUT);
  pinMode(LIGHT4, OUTPUT);
}

void loop() {
  long duration;
  float distance;

  // Send a 10µs pulse to the trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Use pulseInLong instead of pulseIn for better reliability on ESP32
  duration = pulseInLong(ECHO_PIN, HIGH);

  // Convert time to distance in cm
  distance = duration * 0.0343 / 2;

  // Print the distance in Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If an object is detected within 10 cm, turn the LED ON
  if (distance > 0 && distance <= 10) {  
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  if (distance > 10 && distance <= 20) {  
    digitalWrite(LIGHT1, HIGH);
    digitalWrite(LIGHT2, HIGH);
  } else {
    digitalWrite(LIGHT1, LOW); 
    digitalWrite(LIGHT2, LOW);
  }
  if (distance > 20 && distance <= 50) {  
    digitalWrite(LIGHT3, HIGH);
    digitalWrite(LIGHT4, HIGH);
  } else {
    digitalWrite(LIGHT3, LOW);
    digitalWrite(LIGHT4, LOW);
  }

  delay(500);  // Small delay to prevent excessive sensor readings
}
