#include <Servo.h>

#define in1 4 
#define in2 5 
#define in3 6 
#define in4 7 
Servo motor_1;
int servo1 = 80;
int bt_data;

void setup()
{
  
Serial.begin(9600); 

pinMode(in1, OUTPUT); 
pinMode(in2, OUTPUT); 
pinMode(in3, OUTPUT); 
pinMode(in4, OUTPUT); 
pinMode(8, OUTPUT); 
motor_1.attach(11);
motor_1.write(servo1);
delay(1000);
}

void loop()
{

if(Serial.available() > 0)
{     
bt_data = Serial.read(); 
Serial.println(bt_data);
}

     if(bt_data == 1){forword(); }  
else if(bt_data == 2){backword();}  
else if(bt_data == 3){turnLeft();}  
else if(bt_data == 4){turnRight();} 
else if(bt_data == 5){Stop();}

}


else if (bt_data == 10){digitalWrite(8, HIGH);}
else if (bt_data == 11){digitalWrite(8, LOW);}     

else if (bt_data == 12)
  {
      servo1 = servo1+5;
      if(servo1>180){servo1 = 180;}
      motor_1.write(servo1);
      delay(100);  
  }

else if (bt_data == 13)
  {
      servo1 = servo1-5;
      if(servo1<0){servo1 = 0;}
      motor_1.write(servo1);
      delay(100);  
  }

}



void forword(){ 
digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin  
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
}

void backword(){ 
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
}

void turnLeft(){ 
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
}

void turnRight(){ 
digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
}

void Stop(){ //stop
digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, LOW); //Right Motor backword Pin 
digitalWrite(in3, LOW); //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 
}
