// Pin yang terhubung ke LED
const int ledGreenPin = D5;
const int ledRedPin = D6;
const int VibPin1 = D1;
const int VibPin2 = D2;

void setup() {
  // Inisialisasi pin sebagai output
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledRedPin, OUTPUT);
  pinMode(VibPin1, INPUT);
  pinMode(VibPin2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Baca nilai sensor getaran
  int sensorValue1 = digitalRead(VibPin1);
  Serial.print("Nilai Sensor Getaran 1: ");
  Serial.println(sensorValue1);

  int sensorValue2 = digitalRead(VibPin2);
  Serial.print("Nilai Sensor Getaran 2: ");
  Serial.println(sensorValue2);

  // Logika AND
  if (sensorValue1 == HIGH && sensorValue2 == HIGH) {
    // Kedua sensor bernilai 1 (HIGH)
    digitalWrite(ledGreenPin, HIGH);
    digitalWrite(ledRedPin, LOW);
  } else {
    // Setidaknya satu sensor bernilai 0 (LOW)
    digitalWrite(ledGreenPin, LOW);
    digitalWrite(ledRedPin, HIGH);
  }

  delay(1000);
}