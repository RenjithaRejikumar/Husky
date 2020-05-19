#include<SoftwareSerial.h>

/* Create object named bt of the class SoftwareSerial */ 
SoftwareSerial bt(2,3); /* (Rx,Tx) */  
void setup() {
  // put your setup code here, to run once:
  bt.begin(9600);  /* Define baud rate for software serial communication */
  Serial.begin(9600); /* Define baud rate for serial communication */

}

void loop() {
  // put your main code here, to run repeatedly:
if (bt.available())  /* If data is available on serial port */
    {
     Serial.write(bt.read()); /* Print character received on to the serial monitor */
    }
}
