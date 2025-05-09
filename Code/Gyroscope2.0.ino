#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  pinMode(2, OUTPUT);

  if (!mpu.testConnection()) {
    Serial.println("MPU6050 verbinding mislukt!");
    while (1);
  }
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  // Versnelling omzetten naar 'g'-waarden om een kanteling in de drie richtingen te kunnen bepalen.
  float fax = ax / 16384.0;
  float fay = ay / 16384.0;
  float faz = az / 16384.0;

  // Check of het handvat ongeveer vlak gehouden wordt
  if (abs(fax) < 0.1 && abs(fay) < 0.1 && faz > 0.9) { //absolute waarde van de  drie richtingen vergelijken met een bepaalde hoek gebruikt als marge voor "vlak"
    Serial.println("vlak");
    digitalWrite(2, HIGH);
  } else {
    // Bereken kantelhoek in graden
    int angle = atan2(ay, ax) * 180 / PI;
    digitalWrite(2, LOW);

    // Zorg dat de hoek tussen 0 en 360 ligt
    if (angle < 0) {
      angle += 360;
    }

    Serial.println(angle);
  }

  delay(100); // kleine vertraging
}