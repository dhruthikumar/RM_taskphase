//Motor A connections
int ena12 = 10;
int input1 = 7;
int input2 = 4;

//Motor B connections
int ena34 = 3;
int input3 = 2;
int input4 = 12;

int dir;

void setup() {
  //Set motor control pins to outputs
  pinMode (input1, OUTPUT);
  pinMode (input2, OUTPUT);
  pinMode (ena12, OUTPUT);
  pinMode (input3, OUTPUT);
  pinMode (input4, OUTPUT);
  pinMode (ena34, OUTPUT);

  Serial.begin(9600); //opens serial port, sets data rate to 9600 bps 

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
  
  //Prompt for the user to enter a value
  Serial.println("Enter 1 for clockwise and 2 for anticlockwise for motor A: "); 
  Serial.println("(motor B will have opposite direciton)"); 
  while(Serial.available()==0){}
  
  if (Serial.available() > 0) {
    dir = Serial.parseInt(); //returns the next valid integer
    Serial.print("Received: ");
    Serial.println(dir);
    if (dir == 1){
      //clockwise rotation for A
      digitalWrite(input1, LOW);
	    digitalWrite(input2, HIGH);
      
      //anticlockwise rotation for B
      digitalWrite(input4, HIGH);
	    digitalWrite(input3, LOW);
    }
    else if (dir == 2){
      //anticlockwise rotation for A
      digitalWrite(input1, HIGH);
	    digitalWrite(input2, LOW);
      
      //clockwise rotation for B
      digitalWrite(input4, LOW);
	    digitalWrite(input3, HIGH);
    }
    else{
      //Invalid input
      Serial.println("Invalid input");
    }
  }
  delay(2000);
}
