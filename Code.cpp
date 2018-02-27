#include <Joystick.h>

Joystick_ Joystick;

byte AN1 = A0;
byte AN2 = A1;

byte gears[4][3] = {{2,4,6,7},
                    {0,0,0,0},
                    {1,3,5,8}};

byte NEUTRAL = 0;
byte oldoutput = NEUTRAL;

void setup() {
  // put your setup code here, to run once:
 pinMode(AN1, INPUT);
 pinMode(AN2, INPUT);

 Serial.begin(9600);
 Joystick.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = map(analogRead(AN1), 500, 730, 0, 3); 
  int y = map(analogRead(AN2), 10, 580, 0, 2);

  byte output = gears[x][y];

   if(oldoutput != output) {
     Joystick.setButton(oldoutput, LOW);
     oldoutput = output; 
   }
   
   if (output != NEUTRAL) {
       Joystick.setButton(output,HIGH);
   }
}
