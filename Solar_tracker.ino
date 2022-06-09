#include <LiquidCrystal.h> 
#include <Servo.h>

void UpDown();
void LeftRight();

Servo servo1;
Servo servo2;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  
  lcd.begin(16, 2); 
  lcd.print("Tolerence: "); 
  servo1.attach(9);
  servo2.attach(10); 
  
  servo1.write(90); 
  servo2.write(90); 
}
void loop(){
 
 float Tolerence = 0;
  
 int sensorTop = analogRead(A0);
 int sensorBottom = analogRead(A1);
 int sensorLeft = analogRead(A3);
 int sensorRight = analogRead(A4);

 int sensorTest1 = sensorTop - sensorBottom;
 int sensorTest2 = sensorBottom - sensorTop;
 int sensorTest3 = sensorLeft - sensorRight;
 int sensorTest4 = sensorRight - sensorLeft;
   
 int TolerenceValue = analogRead(A2);
 Tolerence = (TolerenceValue * (5.0 / 1023.0))*2;
    
 lcd.setCursor(0,1);
 lcd.print(Tolerence);
 
 if ((sensorTest1 >= 0)&&(sensorTest1 >= Tolerence)) 
 	{
  	 UpDown(sensorTop, sensorBottom);
 	}	
  
 if((sensorTest2 >= 0)&&(sensorTest2 >= Tolerence))
 	{
 	 UpDown(sensorTop, sensorBottom);
 	}
 
 if((sensorTest3 >= 0)&&(sensorTest3 >= Tolerence)) 
 	{
     LeftRight(sensorLeft, sensorRight);
 	}
 
 if((sensorTest4 >= 0)&&(sensorTest4 >= Tolerence)) 
  	{
  	LeftRight(sensorLeft, sensorRight);
  	} 
 
 delay(10); 
}

void UpDown(int sensorTop, int sensorBottom){
  
  int pos1= servo1.read();
    
  if(sensorTop < sensorBottom) 
    { 
     pos1 = --pos1; 
    }
  	 else
     {
      pos1 = ++pos1;
     }
  servo1.write(pos1); 
}

void LeftRight(int sensorLeft, int sensorRight){
  
 int pos2= servo2.read();
 if(sensorLeft < sensorRight)
   { 
    pos2 = --pos2;
   }
  	else
    {
     pos2 = pos2 + 1;
    }
  servo2.write(pos2);
}
//
