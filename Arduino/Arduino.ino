#include <Servo.h>
#define flame 7
#define warning_led 5
#define gas 6

Servo myservo;
String s1 = "UnSafe";
String s2 = "Safe.."; 

void setup()
{
    myservo.attach(8); // setup chân servos
    pinMode(flame,INPUT);
    pinMode(warning_led,OUTPUT);
    digitalWrite(warning_led, HIGH);
    Serial.begin(115200);
    myservo.write(0);
}

void warning()
{
      digitalWrite(warning_led,LOW);
      delay(100);
      digitalWrite(warning_led,HIGH);
      delay(100);   
}

void loop()
{
  int i = 0;   
  while( i <  181 )
  {
    while( digitalRead(flame) == false || digitalRead(gas) == false ) 
    {
      myservo.write(i);
      Serial.println(s1);
      Serial.flush();
      delay(10);
      warning();
    }
     myservo.write(i);
     delay(10);
     i++;
  }
  
  for ( i = 180 ; i > 0 ; i--)
  {
    while( digitalRead(flame) == false || digitalRead(gas) == false) 
    {
      myservo.write(i);
      Serial.println(s1);
      Serial.flush();
      delay(10);
      warning();
    }
       myservo.write(i);
      delay(10);
  }
  Serial.println(s2);
  delay(300);

}
