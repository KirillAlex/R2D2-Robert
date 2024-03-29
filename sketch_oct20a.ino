

#include <AFMotor.h>
#include "Servo.h"

Servo  my_servo;


AF_DCMotor motor1(3); 
AF_DCMotor motor2(2); 

char command; 

void setup() 
{       
  Serial.begin(9600); 
  
    my_servo.attach(10); 
}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop(); 
    
    Serial.println(command);
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
      case 'G':
      Turn_Head_right();
      break;
      case 'I':
      Turn_Head_left();
      break;
      case 'W':
      head_forward();
      break;
      
    }
  } 
}
void Turn_Head_right()
{
  my_servo.write(180);
   
   }
   void Turn_Head_left()
{
  my_servo.write(90);
   
   }
   void   head_forward()
{
  my_servo.write(0);
  
   }
   
void forward()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD); 
  motor2.setSpeed(255);
  motor2.run(FORWARD); 
}

void back()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD);
}

void left()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD); 
  motor2.setSpeed(255);
  motor2.run(BACKWARD); 
}

void right()
{
  motor1.setSpeed(255);
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
}

void Stop()
{
  motor1.setSpeed(0);
  motor2.run(RELEASE); 
  motor2.setSpeed(0);
  motor2.run(RELEASE); 
}
