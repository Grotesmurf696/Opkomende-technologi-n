// Victor Fransen en Sam Verkimpe

//Libraries voor werking gyroscoop en neopixel
#include <Wire.h>
#include <MPU6050.h>
MPU6050 mpu;
#include <Adafruit_NeoPixel.h>

//code voor string uitlezen
String line = "0";
bool VolledigeString = false;
int angle;

//Led strip definieren
#define LED_PIN 6
#define LED_COUNT 20
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int aantalLeds = 20;

//Waarden voor ruisuitwerking
unsigned long vorigeTijd = 0;
float zHoek = 0;
int vorige_fgz = 0;
float gefilterdeX = 0;
float alpha = 0.1;

//schem
const int knopPin = 7;
const int motorPin = 2;
unsigned long knoptijd;
int level = 1;

void setup() {
  //seriele poort openen, en communcatie met gyro
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();

  //Ledsrip parameters
  strip.begin();
  strip.show();
  strip.setBrightness(30);

  //In/output definieren
  pinMode(motorPin, OUTPUT);
  pinMode(knopPin, INPUT_PULLUP);

  //alle leds even testen
  for(int i= 0; i < strip.numPixels(); i ++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0));
    strip.show();
    delay(50);
    strip.setPixelColor(i, strip.Color(0,0,0));
    strip.show();

  }
  for (int i = 0; i < strip.numPixels(); i ++){
    strip.setPixelColor(i, strip.Color(0, 255, 0));
    strip.show();
    delay(50);
    strip.setPixelColor(i, strip.Color(0,0,0));
    strip.show();
  
  }
  for (int i = 0; i < strip.numPixels(); i ++){
    strip.setPixelColor(i, strip.Color(0, 0, 255));
    strip.show();
    delay(50);
    strip.setPixelColor(i, strip.Color(0,0,0));
    strip.show();
    
    
  }
}

void loop() {
// gyroscoopwaarden uitlezen
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

  // Draaihoek integreren met afgeronde fgz aarde omdat ik den dat dat minder ruis geeft?
  zHoek += round(fgz) * deltaT;
  
  // Hoek beperken van 0 tot 360°
  if (zHoek < 0) zHoek += 360;
  if (zHoek >= 360) zHoek -= 360;

  int xHoek = round(atan2(faz, fax) * 180 / PI); //Hoek om de X as berekenen (beweging in de y richting)

  //Neopixel
  if (xHoek) {
    Serial.println(line);  // Debug output
    int hoekGetal = xHoek;
    int Hoekdeel = hoekGetal / 18;
    
    strip.setPixelColor(Hoekdeel, strip.Color(255,0,0));
    strip.setPixelColor(Hoekdeel - 1, strip.Color(0,255,0));
    strip.setPixelColor(Hoekdeel + 1, strip.Color(0,255,0));
    strip.show();

    strip.setPixelColor(Hoekdeel, strip.Color(0,0,0));
    strip.setPixelColor(Hoekdeel - 1, strip.Color(0,0,0));
    strip.setPixelColor(Hoekdeel + 1, strip.Color(0,0,0));
    strip.show();
  }

  //where is waldo?
  int knopstatus = digitalRead(knopPin); //knop uitlezen

  //Voor protopie: hoeken tussen -90 en 90
  if (zHoek > 180){
      zHoek -=360;
  }
  xHoek -=90;
  if (xHoek > 180){
    xHoek -= 360;
  }
  xHoek= xHoek*-1; //Hoek omdraaien van teken omdat het makkelijker was in protopie

  gefilterdeX = alpha * xHoek + (1 - alpha) * gefilterdeX; // xHoek filteren om op en neer springen te vermeiden (lowpassfilter)

  Serial.print("Y||");
  Serial.println(round(gefilterdeX));
  Serial.print("X||");
  Serial.println(round(zHoek));

//protopie: levels where is waldo
  if(zHoek<=65 && zHoek>=50 && gefilterdeX >-60 && gefilterdeX<-40 && knopstatus == LOW && level == 1){
    knoptijd = millis();
    digitalWrite(motorPin, HIGH);
    level += 1;
    Serial.print("level||");
    Serial.println(level);
  }
  else if(zHoek<=-35 && zHoek>=-45 && gefilterdeX >20 && gefilterdeX<30 && knopstatus == LOW && level == 2){
    knoptijd = millis();
    digitalWrite(motorPin, HIGH);
    level += 1;
    Serial.print("level||");
    Serial.println(level);
  }
  else if(zHoek<=45 && zHoek>=35 && gefilterdeX >35 && gefilterdeX <45 && knopstatus == LOW && level == 3){
    knoptijd = millis();
    digitalWrite(motorPin, HIGH);
    level += 1;
    Serial.print("level||");
    Serial.println(level);
  }

  if(motorPin&& millis()-knoptijd>= 800){
    digitalWrite(motorPin, LOW);
  }
}