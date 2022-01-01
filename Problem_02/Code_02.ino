//Switch on led when push button is pressed

int buttonState = 0;
int ledPin = 13;
int buttonPin = 2;

void setup()
{
  pinMode(buttonPin, INPUT); //configures pin 2 as an input 
  pinMode(ledPin, OUTPUT); //configures pin 13 as an output
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) { //if button is pressed
  	digitalWrite(ledPin, HIGH); //turn the led on
  } 
  else {
    digitalWrite(ledPin, LOW); 
  }
}