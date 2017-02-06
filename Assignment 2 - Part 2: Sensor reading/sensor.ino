
int analogPin = 0;
int photocellReading;     // the analog reading from the sensor divider
int LEDpin = 10;          // connect Red LED to pin 11 (PWM pin)
int LEDbrightness; 


void setup() {
  // put your setup code here, to run once:
//  pinMode(ledPin , INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  photocellReading = analogRead(A0);
  Serial.print("Analog reading = ");
  Serial.println(photocellReading);

  float voltage = photocellReading * 0.0048;
  float ldr = ((5-voltage) * 1000 ) / voltage;

  float lux = 500 / ldr;

  Serial.print("lux = ");
  Serial.println(lux);
  
//  photocellReading = 1023 - photocellReading;
  //now we have to map 0-1023 to 0-255 since thats the range analogWrite uses
  LEDbrightness = map(photocellReading, 0, 1023, 0, 255);
  analogWrite(LEDpin, LEDbrightness);
 
  delay(100);
}
