#include <Arduino.h>

const int sensorPin = D2; // Pin sensor IR Octupular Speed
unsigned long lastTime = 0;
volatile int count = 0;
int rpm = 0;

void IRAM_ATTR countPulse() {
  count++;
}

void setup() {
  Serial.begin(115200);
  pinMode(sensorPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(sensorPin), countPulse, RISING);
}

void loop() {
  unsigned long currentTime = millis();

  // Update RPM every second
  if (currentTime - lastTime >= 1000) {
    detachInterrupt(digitalPinToInterrupt(sensorPin)); // Disable interrupt during calculation
    rpm = (count * 60) / 2; // Calculate RPM
    count = 0; // Reset count
    attachInterrupt(digitalPinToInterrupt(sensorPin), countPulse, RISING); // Re-enable interrupt
    lastTime = currentTime;

    // Print RPM to Serial Monitor
    Serial.print("RPM: ");
    Serial.println(rpm);
  }
}
