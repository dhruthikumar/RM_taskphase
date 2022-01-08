//Motor connections
int ena12 = 10;
int input1 = 7;
int input2 = 4;
int buttonState = 0;
int buttonPin = 12;

void setup() {
  //Set motor control pins to outputs
  pinMode (input1, OUTPUT);
  pinMode (input2, OUTPUT);
  pinMode (ena12, OUTPUT);

  pinMode(buttonPin, INPUT); 
  
  //Turn off motor - Initial state
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  digitalWrite(ena12, LOW);

}

void loop() {
  //Set the motor to highest speed 
  analogWrite(ena12, 255);
  
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
  	digitalWrite(input1, LOW);
	digitalWrite(input2, HIGH);
  } 
  else {
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
  }
}