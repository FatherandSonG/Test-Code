/************************************************/
#include <Servo.h>
/************************************************/
Servo myservo;//create servo object to control a servo
/************************************************/
void setup()
{
  myservo.attach(9);//attachs the servo on pin 9 to servo object
  myservo.write(0);//back to 0 degrees 
  delay(1000);//wait for a second
}
/*************************************************/
void loop()
{  
  myservo.write(15);//goes to 15 degrees 
  delay(1000);//wait for a second
  myservo.write(90);//goes to 30 degrees 
  delay(1000);//wait for a second.33

}
/**************************************************/

