//Inker Husky Firmware BottomTest
//@Author Akhil P Jacob
#include <Wire.h> 
#include <Adafruit_PWMServoDriver.h>
int led=13;
 
#define MIN_PULSE_WIDTH       650
#define MAX_PULSE_WIDTH       2350
#define FREQUENCY             50
 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

//Servo Motor initialization

int A = 0;
int B = 1;
int C = 2;
int D = 3;
int E = 4;
int F = 5;
int G = 6;
int H = 7;
int pos1;
int pos2=90;
int pos3=10;

int motor1=2;
int motor2=3;
int motor3=4;
int motor4=5;
int motor5=6;
int motor6=7;
int motor7=8;
int motor8=9;

String action;

void setup()
{
    pwm.begin();
    pwm.setPWMFreq(FREQUENCY);
    Serial.begin(9600);
    Serial.println("*************Inker Husky Actuator Tester************* ");
    pinMode(led,OUTPUT);
    pinMode(motor1,OUTPUT);
    pinMode(motor2,OUTPUT);
    pinMode(motor3,OUTPUT);
    pinMode(motor4,OUTPUT);
    pinMode(motor5,OUTPUT);
    pinMode(motor6,OUTPUT);
    pinMode(motor7,OUTPUT);
    pinMode(motor8,OUTPUT);
    

     moveMotor_angle(90, A);
      moveMotor_angle(90, B);
      moveMotor_angle(90, C);
      moveMotor_angle(90, D);
      moveMotor_angle(90, E);
      moveMotor_angle(90, F);
      moveMotor_angle(90, G);
      moveMotor_angle(90, H);
}


void moveMotor_angle(int controlIn, int motorOut)
{
  Serial.println("Executing : moveMotor_angle");
  int pulse_wide, pulse_width, potVal;
  
  // Read values from potentiometer
  
  
  // Convert to pulse width
  pulse_wide = map(controlIn, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  pulse_width = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  
  //Control Motor
  pwm.setPWM(motorOut, 0, pulse_width);
 
 
}


void loop()
{
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW); 
    delay(500);


    if(Serial.available()>0)
 {
    action=Serial.readString();
    action.trim();

      char check=action[0];
      int check2=action[1]-48;
      int check3=action[2]-48;
      int check4=action[3]-48;
      int angle=0;      
      angle=check2*10+check3;
      angle=angle*10+check4;         
      Serial.println(check);



    if(check=='A')
       {
         moveMotor_angle(angle, A);  
       }
    else if(check=='B')
       {
          moveMotor_angle(angle, B); 
       }
    else if(check=='C')
       {
         moveMotor_angle(angle, C); 
       }
    else if(check=='D')
       {
         moveMotor_angle(angle, D); 
       }
    else if(check=='E')
       {
         moveMotor_angle(angle, E); 
       }
    else if(check=='F')
       {
         moveMotor_angle(angle, F); 
       }
    else if(check=='G')
       {
         moveMotor_angle(angle, G); 
       }
    else if(check=='H')
       {
         moveMotor_angle(angle, H); 
       }

    else if(check=='8')
       {
         digitalWrite(motor1,HIGH);
         digitalWrite(motor2,LOW);

         digitalWrite(motor3,HIGH);
         digitalWrite(motor4,LOW);

         digitalWrite(motor5,HIGH);
         digitalWrite(motor6,LOW);

         digitalWrite(motor7,HIGH);
         digitalWrite(motor8,LOW);
       }

      else if(check=='2')
       {
         digitalWrite(motor1,LOW);
         digitalWrite(motor2,HIGH);

         digitalWrite(motor3,LOW);
         digitalWrite(motor4,HIGH);

         digitalWrite(motor5,LOW);
         digitalWrite(motor6,HIGH);

         digitalWrite(motor7,LOW);
         digitalWrite(motor8,HIGH);
       }

      else if(check=='4')
       {
         digitalWrite(motor1,LOW);
         digitalWrite(motor2,HIGH);

         digitalWrite(motor3,HIGH);
         digitalWrite(motor4,LOW);

         digitalWrite(motor5,LOW);
         digitalWrite(motor6,HIGH);

         digitalWrite(motor7,HIGH);
         digitalWrite(motor8,LOW);
       }

      else if(check=='6')
       {
         digitalWrite(motor1,HIGH);
         digitalWrite(motor2,LOW);

         digitalWrite(motor3,LOW);
         digitalWrite(motor4,HIGH);

         digitalWrite(motor5,HIGH);
         digitalWrite(motor6,LOW);

         digitalWrite(motor7,LOW);
         digitalWrite(motor8,HIGH);
       }
  
      else if(check=='5')
       {
         digitalWrite(motor1,LOW);
         digitalWrite(motor2,LOW);

         digitalWrite(motor3,LOW);
         digitalWrite(motor4,LOW);

         digitalWrite(motor5,LOW);
         digitalWrite(motor6,LOW);

         digitalWrite(motor7,LOW);
         digitalWrite(motor8,LOW);
       }

   else if(check=='x')//sitting
       {
         for(pos1=90;pos1>=10;pos1-=1)
         {
          moveMotor_angle(pos1, C);
          moveMotor_angle(pos1, B);
          moveMotor_angle(pos1, E);
          moveMotor_angle(pos1, H);

        
          int finalVal=pos2++;

          moveMotor_angle(pos2, A);
          moveMotor_angle(pos2, D);
          moveMotor_angle(pos2, F);
          moveMotor_angle(pos2, G);

            delay(2); 
         
         }

       
       }

   else if(check=='y')//standing
       {
          pos1=90;
          moveMotor_angle(90, C);
          moveMotor_angle(90, B);
          moveMotor_angle(90, E);
          moveMotor_angle(90, H);
          moveMotor_angle(90, A);
          moveMotor_angle(90, D);
          moveMotor_angle(90, F);
          moveMotor_angle(90, G);

       }


 }

}








void stop()
{
   
}

