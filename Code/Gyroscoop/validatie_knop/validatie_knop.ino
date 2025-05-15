const int knoppin = 7;
void setup() {
  Serial.begin(9600);
  pinMode(knoppin, INPUT_PULLUP);
}

void loop() {
  int knopstatus = digitalRead(knoppin);
  if(knopstatus == LOW){
    Serial.print("knop ingedrukt");
  }
}
