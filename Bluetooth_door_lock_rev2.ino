#include <SoftwareSerial.h> 
#include <Servo.h> 

SoftwareSerial MyBlue(0,1); // RX | TX 
Servo Servo1; 

int servomotor = 9;
int initialval, finalval;
char input;

void setup() 
{   
 Serial.begin(9600); 
 MyBlue.begin(9600); 
 Servo1.attach(servomotor); 
 Servo1.write(120);
 Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 
} 
void loop() 
{ 
 if (MyBlue.available()) 
 {
    input = MyBlue.read(); 
 if (input == 'O') 
 { 
    initialval = Servo1.read();
    if (initialval<180)
    {
    do
    {
      finalval = initialval+10;
      initialval=finalval;
      Servo1.write(finalval); //open the door
      delay(200);
    } while (finalval<=180);
    }

    else if (initialval>180)
    {
    do {
         finalval = initialval-10;
         initialval=finalval;      
         Servo1.write(finalval); //open the door
         delay(200);
    } while (finalval>=180);
    }
       Serial.println("The door is opened"); 
  }
 
 else if (input == 'C') 
 { 
  int initialval = Servo1.read();
    if (initialval<0)
    {
    do
    {
      finalval = initialval+10;
      initialval=finalval;      
      Servo1.write(finalval); //open the door
      delay(200);
    } while (finalval<=0);
    }

    else if (initialval>0)
    {
    do {
         int finalval = initialval-10;
         initialval=finalval;      
         Servo1.write(finalval); //open the door
         delay(200);
    } while (finalval>=0);
    }
   Serial.println("The door is locked"); 
 } 
}
}  
