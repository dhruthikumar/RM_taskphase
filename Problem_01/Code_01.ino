//Blink led for 1s, 2s and 3s in loop

int ledPin = 13; 

void setup() {
  
  pinMode(ledPin, OUTPUT); //configures pin 13 as an output 
}

void loop() {
  digitalWrite(ledPin, HIGH);   
  delay(1000); // dealy of 1s              
  digitalWrite(ledPin, LOW);    
  delay(1000); // dealy of 1s
  digitalWrite(ledPin, HIGH);   
  delay(2000); // dealy of 2s              
  digitalWrite(ledPin, LOW);    
  delay(2000); // dealy of 2s
  digitalWrite(ledPin, HIGH);   
  delay(3000); // dealy of 3s              
  digitalWrite(ledPin, LOW);    
  delay(3000); // dealy of 3s 
}