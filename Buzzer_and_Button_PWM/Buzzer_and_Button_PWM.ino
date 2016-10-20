//Turns on and off a LED ,when pressings button attach to pin12
/**********************************/
const int keyPin = 8; //the number of the key pin
const int buzzer = 9;//the number of the  pin
const int ledPin= 13;
/**********************************/
void setup()
{
  pinMode(keyPin,INPUT);//initialize the key pin as input 
  pinMode(buzzer,OUTPUT);//initialize the led pin as output
  pinMode(ledPin,OUTPUT);
}
/**********************************/
void loop()
{
  unsigned char i; //define a variable
 while(digitalRead(keyPin)==HIGH)
 {
   for (int a=0; a<=500;a++)               //loop from 0 to 255
  {
    analogWrite(buzzer, a);
    digitalWrite(ledPin,HIGH);
    //analogWrite(ledPin2, a);
    //analogWrite(ledPin3, a);// set the brightness of pin 9:
    delay(10);                             //wait for 8 microseconds            
    digitalWrite(ledPin,LOW);  
  }
  //  for (int a=255; a>=0;a--)             //loop from 255 down to 0
  //{
   // analogWrite(buzzer, a);               // set the brightness of pin 9:
    //analogWrite(ledPin2, a);
    //analogWrite(ledPin3 , a);
  //  delay(10);                             //wait for 8 microseconds   
  }
 // delay(500);                             //wait for 800 microseconds
  //}
  analogWrite(buzzer,0);
 }
/************************************/
