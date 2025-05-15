#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

unsigned long vorigeTijd = 0;
float zHoek = 0;
int vorige_fgz = 0;

float angleXFiltered = 0;
float alpha = 0.1;

const int knopPin = 7;
const int motorPin = 2;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  pinMode(motorPin, OUTPUT);
  pinMode(knopPin, INPUT_PULLUP);
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 verbinding mislukt!");
    while (1);
  }
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);
  int16_t gx, gy, gz;
  mpu.getRotation(&gx, &gy, &gz);
  
  // Versnelling omzetten naar 'g'-waarden om een kanteling in de drie richtingen te kunnen bepalen.
  float fax = ax / 16384.0;
  float fay = ay / 16384.0;
  float faz = az / 16384.0;
  float fgz = (gz / 131.0)-2.3;

  // Tijd sinds laatste meting
  unsigned long huidigeTijd = millis();
  float deltaT = (huidigeTijd - vorigeTijd) / 1000.0; // in seconden
  vorigeTijd = huidigeTijd;

  // Draaihoek integreren
  zHoek += round(fgz) * deltaT;
  
  // Hoek beperken van 0 tot 360°
  if (zHoek < 0) zHoek += 360;
  if (zHoek >= 360) zHoek -= 360;

  int Xangle = round(atan2(faz, fax) * 180 / PI);

  int knopstatus = digitalRead(knopPin);
  if (zHoek > 180){
      zHoek -=360;
  }
  Xangle -=90;
  if (Xangle > 180){
    Xangle -= 360;
  }
  Xangle= Xangle*-1;

  angleXFiltered = alpha * Xangle + (1 - alpha) * angleXFiltered;
  Serial.print("Y||");
  Serial.println(round(angleXFiltered));
  Serial.print("X||");
  Serial.println(round(zHoek));
  if(zHoek<=60 && zHoek>=55 && angleXFiltered >-55 && angleXFiltered<-44 && knopstatus == LOW){
    digitalWrite(motorPin, HIGH);
  }
  else{
    digitalWrite(motorPin, LOW);
  }
}