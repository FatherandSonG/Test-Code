#include <Stepper.h>
 
//the steps of a circle
#define STEPS 100
 
//set steps and the connection with MCU
Stepper stepper(STEPS, 10, 11, 12, 13);
 
//available to store previous value
int previous = 0;
int val=0;
 
void setup()
{
  //speed of 180 per minute
  stepper.setSpeed(360);
  Serial.begin(9600);
}
 
void loop()
{
  //get analog value
  for (val=0; val<10000; val++)
  {
  Serial.println(val);
  stepper.step(val - previous);
  previous = val;
 
  }
  for (val=10000; val<0; val--)
  {
  Serial.println(val);
  stepper.step(val - previous);
  previous = val;
 
  }
  
  //current reading minus the reading of history
 // stepper.step(val - previous);
 
  //store as prevous value
  //previous = val;
}

