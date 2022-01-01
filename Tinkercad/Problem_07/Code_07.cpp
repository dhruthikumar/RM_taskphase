#include <Servo.h> //Including the servo library

int buttonState = 0;
int cm = 0;
int inches = 0;
int inputValue = 0;
int outputValue = 0;

Servo myServo; 

long sensorReading(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT); 
  return pulseIn(echoPin, HIGH); 
}

void setup()
{
  Serial.begin(9600);  
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(12, INPUT); 
  pinMode(A0, INPUT); 
  pinMode(5, OUTPUT); 
  myServo.attach(9); 
  myServo.write (0); 
}

void loop()
{
  //ultrasonic sensor, servo and 3 leds (RGB)
  cm = 0.01723 * sensorReading(7, 7); 
  inches = (cm / 2.54); 
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.print(inches);
  Serial.println("in");
  
  if (cm >= 50) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    myServo.write (0);
  }
  if (cm < 50 && cm > 15) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    myServo.write (90);
  }
  if (cm <= 15) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    myServo.write (180);
  }
  delay(100); // Wait for 100 millisecond(s)
  
  //button to turn the blue led on and off
  buttonState = digitalRead(12);
  if (buttonState == HIGH) {
  	digitalWrite(5, HIGH);
  } 
  else {
    digitalWrite(5, LOW);
  }
  
  //potentiometer reading to control the brightness of blue led
  inputValue = analogRead(A0); 
  outputValue = map(inputValue, 0, 1023, 0, 255); 
  analogWrite(5, outputValue); 
  delay(2); 
  
}