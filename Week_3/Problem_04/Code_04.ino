//Motor A connections
int ena12 = 10;
int input1 = 7;
int input2 = 4;

//Motor B connections
int ena34 = 3;
int input3 = 2;
int input4 = 12;

void setup() {
  //Set motor control pins to outputs
  pinMode (input1, OUTPUT);
  pinMode (input2, OUTPUT);
  pinMode (ena12, OUTPUT);
  pinMode (input3, OUTPUT);
  pinMode (input4, OUTPUT);
  pinMode (ena34, OUTPUT);

  //Turn off motors - Initial state
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  digitalWrite(ena12, LOW);
  digitalWrite(input3, LOW);
  digitalWrite(input4, LOW);
  digitalWrite(ena34, LOW);

}

void loop() {
  //Set the motors to maximum speed
  analogWrite(ena12, 255);
  analogWrite(ena34, 255);

  //Turn on motors
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
  digitalWrite(input4, LOW);
  digitalWrite(input3, HIGH);

  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
	analogWrite(ena12, i);
	analogWrite(ena34, i);
	delay(50);
  }
	
  // Decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i) {
	analogWrite(ena12, i);
	analogWrite(ena34, i);
	delay(50);
  }
	
  //Turn off motors
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  digitalWrite(input4, LOW);
  digitalWrite(input3, LOW);

  delay(2000);
}

