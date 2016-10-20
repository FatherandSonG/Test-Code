//Turns on and off a LED ,when pressings button attach to pin12
/**********************************/
const int keyPin = 8; //the number of the key pin
const int buzzer = 12;//the number of the  pin
/**********************************/
void setup()
{
  pinMode(keyPin,INPUT);//initialize the key pin as input 
  pinMode(buzzer,OUTPUT);//initialize the led pin as output
}
/**********************************/
void loop()
{
  unsigned char i; //define a variable
 while(digitalRead(keyPin)==HIGH)
 {
   //output an frequency
   for(i=0;i<80;i++)
   {
    digitalWrite(buzzer,HIGH);
    delay(5);//wait for 1ms
    digitalWrite(buzzer,LOW);
    delay(3);//wait for 1ms
    }
    //output another frequency
     for(i=0;i<100;i++)
      {
        digitalWrite(buzzer,HIGH);
        delay(6);//wait for 2ms
        digitalWrite(buzzer,LOW);
        delay(4);//wait for 2ms
      }
  }
  
  
  
  //read the state of the key value
  //and check if the kye is pressed
  //if it is,the state is HIGH 
 // if(digitalRead(keyPin) ==HIGH )
  //{
    //digitalWrite(buzzer,HIGH);
 
//  }
 // else
  //{
   // digitalWrite(buzzer,LOW);
  //}
}
/************************************/
