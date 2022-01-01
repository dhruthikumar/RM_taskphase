//Display the reading of the ultrasonic sensor on the serial monitor

int inches = 0;
int cm = 0;

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
  Serial.begin(9600);//opens serial port, sets data rate to 9600 bps 
}

void loop()
{
  cm = 0.01723 * sensorReading(4, 4); //measure ping time in cm
  inches = (cm / 2.54); //convert cm to inches 
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  delay(100); //wait for 100 milliseconds
}