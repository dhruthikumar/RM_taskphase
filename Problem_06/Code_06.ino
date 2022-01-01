//Take reading from the ultrasonic sensor and execute the following:
//0-15: turn led off
//15-50: turn led on
//50 and beyond: turn led off

int cm = 0;
int inches = 0;

long sensorReading(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW); //clear the trigger
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10); // sets trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT); // reads the echo pin
  return pulseIn(echoPin, HIGH); //returns the sound wave travel time in microseconds
}

void setup()
{
  Serial.begin(9600); //opens serial port, sets data rate to 9600 bps 
  pinMode(4, OUTPUT); //configures pin 4 as an output
}

void loop()
{
  cm = 0.01723 * sensorReading(7, 7); // measure ping time in cm
  inches = (cm / 2.54); // convert cm to inches 
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.print(inches);
  Serial.println("in");
  
  if (cm >= 50) {
    digitalWrite(4, LOW); //turns led off
  }
  if (cm < 50 && cm > 15) {
    digitalWrite(4, HIGH); //turns led on
  }
  if (cm <= 15) {
    digitalWrite(4, LOW); //turns led off
  }
  
  delay(100); // Wait for 100 millisecond(s)
}