#include <Joystick.h>

Joystick_ Joystick;

int Br1 = 540; // define crossing points From left to right 
int Br2 = 650;
int Br3 = 720;

int G1 = 600;  // Up or down crossing points 
int G2 = 120; 

byte AN1 = A0;
byte AN2 = A1;

byte Bstate; 
byte Bstate1;
byte oldoutput;

void setup() {
  // put your setup code here, to run once:
 pinMode(AN1, INPUT);
 pinMode(AN2, INPUT);  

 Serial.begin(9600);
 Joystick.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
int Reading1 = map(analogRead(AN1), 500, 730, 0, 3); 
int Reading2 = map(analogRead(AN2), 10, 580, 0, 2);

byte output; 

switch (Reading1){ 
  case 0:
  if (Reading2==0){ 
    output = 0; 
  }
  if (Reading2==2){
    output = 1;
  }
  if (Reading2==1){
   output = 8;
  }
    break; 
  case 1: 
  
  if (Reading2==0){
    output = 2;
  }
  
  if (Reading2 == 2){
    output = 3; 
  }
  if (Reading2==1){
    output = 8;
  }
    break;

     case 2: 
  
  if (Reading2==0){
    output = 4;
  }
  
  if (Reading2 == 2){
    output = 5; 
  }
  if (Reading2==1){
    output = 8;
  }
    break;

     case 3: 
  
  if (Reading2==0){
    output = 6;
  }
  
  if (Reading2 == 2){
    output = 7; 
  }
  if (Reading2==1){
    output = 8;
  }
    break;
    
  default:
  output = 8;
}


Serial.print(Reading1);
Serial.print("  ");
Serial.print(Reading2); 
Serial.print("  ");
Serial.println(output);

 if(oldoutput != output){
  Joystick.setButton(oldoutput, LOW);
 }
  
 Joystick.setButton(output,HIGH);
 oldoutput = output; 


 

}
