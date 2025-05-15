#include<Wire.h>
const int MPU=0x68; 
int16_t GyX,GyY,GyZ;

bool voor = false;
bool achter = false;
bool vlak_X = false;
bool links = false;
bool rechts = false;
bool vlak_Y = false;


void  setup(){
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);  
  Wire.write(0);    
  Wire.endTransmission(true);
  Serial.begin(9600);
}
void  loop(){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read(); 

  int part_y = GyY / 3200;
  int part_x = GyX / 3200;

  if (GyX<-600){
    voor = true;
    achter = false;
    vlak_X = false;
  }
  else if(GyX>600){
    voor = false;
    achter = true;
    vlak_X = false;
    }
  else{
    voor = false;
    achter = false;
    vlak_X = true;
    }
  
  if (GyY < -600){
    links = true;
    rechts = false;
    vlak_Y = false;
  }
  else if(GyY > 600){
    links = false;
    rechts =true;
    vlak_Y = false;
  }
  else{
    links = false;
    rechts = false;
    vlak_Y = true;
  }

  if(voor == true){
    if(links == true){
      Serial.println("linksvoor");

    }
    else if(rechts == true){
      Serial.println("rechtsvoor");

    }
    else{
      Serial.println("vooruit");

    }
  }

  else if(achter == true){
    if(links == true){
      Serial.println("linksachter");

    }
    else if(rechts == true){
      Serial.println("rechtachter");

    }
    else{
      Serial.println("achteruit");

    }
  }
  else{
    if(links == true){
      Serial.println("links");

    }
    else if(rechts == true){
      Serial.println("rechts");

    }
    else{
      Serial.println("VLAK");

    }
  }
}