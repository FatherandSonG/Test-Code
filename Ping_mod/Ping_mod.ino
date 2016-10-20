/* Ping))) Sensor Sketch modified for HC-SR04 Ultrasonic Sensor

   This sketch was originally for reading a PING))) ultrasonic rangefinder
   I modified the sketch from the original to add the return on an alternate pin.
   
   The sketch sends a pulse on pin 7 and listens on pin 8 for the echo pulse and returns
   the distance to the closest object in range.The length of the returning pulse is proportional to
   the distance of the object from the sensor.

   The circuit:
	* VCC connection of the HC-SR04 attached to +5V
	* GND connection of the HC-SR04 attached to ground
	* TRIG connection of the HC-SR04 attached to digital pin 7
	* ECHO connection of the HC-SR04 attached to digital pin 8

   original code located at http://www.arduino.cc/en/Tutorial/Ping

   created 3 Nov 2008
   by David A. Mellis
   modified 30 Aug 2011
   by Tom Igoe
   modified 20 October 2016
   by Robin Gambin

   This example code is in the public domain.

 */

// this constant won't change.  It's the pin number
// of the sensor's output:
const int pingPin = 7; //trigger
const int echoPin = 8; //return

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The HC-SR04 is triggered by a HIGH pulse of 8 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(8);
  digitalWrite(pingPin, LOW);

  // HIGH pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(echoPin, HIGH);
   
  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
