//Motor A connections
int ena12 = 10;
int input1 = 7;
int input2 = 4;

//Motor B connections
int ena34 = 3;
int input3 = 2;
int input4 = 12;

int speed = 0;
int cm = 0;
int inches = 0;
int sensorPin = 8;

long sensorReading(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW); //clears the trigger
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10); // sets trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT); // reads the echo pin
  return pulseIn(echoPin, HIGH); //returns the sound wave travel time in microseconds
}

void setup() {
  //Set motor control pins to outputs
  pinMode (input1, OUTPUT);
  pinMode (input2, OUTPUT);
  pinMode (ena12, OUTPUT);
  pinMode (input3, OUTPUT);
  pinMode (input4, OUTPUT);
  pinMode (ena34, OUTPUT);
  
  //Set ultrasonic sensor pin to output
  pinMode (sensorPin,OUTPUT); 

  //Turn off motors - Initial state
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  digitalWrite(ena12, LOW);
  digitalWrite(input3, LOW);
  digitalWrite(input4, LOW);
  digitalWrite(ena34, LOW);
  
  Serial.begin(9600); //opens serial port, sets data rate to 9600 bps 
}

void loop() {
  
  cm = 0.01723 * sensorReading(sensorPin, sensorPin); // measure ping time in cm
  inches = (cm / 2.54); // convert cm to inches 
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.print(inches);
  Serial.println("in");
    
  speed = map (cm, 10, 336, 0, 255);
    
  //Set the motors to the required speed
  analogWrite(ena12, speed);
  analogWrite(ena34, speed);

  //Turn on motors
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
  digitalWrite(input4, LOW);
  digitalWrite(input3, HIGH);
}

