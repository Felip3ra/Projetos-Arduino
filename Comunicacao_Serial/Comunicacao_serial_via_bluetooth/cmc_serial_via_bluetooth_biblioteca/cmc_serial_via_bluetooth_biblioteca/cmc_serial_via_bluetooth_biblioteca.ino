#include <SoftwareSerial.h>

#define led1 4


SoftwareSerial bt_serial(0,1); //RX e TX
String _final;

void setup() {
bt_serial.begin(9600);
pinMode(led1,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  char c = bt_serial.read();
  
  if(c=='L')
  {
    digitalWrite(led1,HIGH);
  }
  if(c == 'D')
  {
    digitalWrite(led1,LOW);
  }
  delay(100);
}
