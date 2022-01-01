//Move the servo to an angle
//Angle must be taken from the user and displayed on serial monitor

#include <Servo.h> //Including the servo library

int angle = 0;
int servoPin = 9;
int servoDelay = 15;

Servo myServo; //create an object for the servo library to control the servo

void setup()
{
  myServo.attach(servoPin); //attach the servo to PWM pin 9
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps 
  myServo.write (angle); //servo is set at 0 degrees
}

void loop()
{
  Serial.print("Enter an angle(0-180) - "); //prompt for the user to enter a value
  while(Serial.available()==0){} //while there is no input data to read do nothing
  if (Serial.available() > 0) { 
    angle = Serial.parseInt(); //returns the next valid integer entered
    Serial.print("received: "); 
    Serial.println(angle); //displays received input on serial monitor
    myServo.write (angle); //rotates servo to the required angle
    delay(servoDelay); //time delay for the servo to reach the position (15ms)
  }
}