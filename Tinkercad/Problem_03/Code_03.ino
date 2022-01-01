//Take reading from the potentiometer to control the brightness of led

int inputValue = 0;
int outputValue = 0;

void setup()
{
  pinMode(A0, INPUT); //configures analog pin A0 as an input 
  pinMode(9, OUTPUT); //configures PWM pin 9 as an output 
  Serial.begin(9600); //opens serial port, sets data rate to 9600 bps 
}

void loop()
{
  inputValue = analogRead(A0); //read the ananlog input
  outputValue = map(inputValue, 0, 1023, 0, 255); //map it to the range of the output
  analogWrite(9, outputValue); //output via led
  Serial.print("sensor = ");
  Serial.print(inputValue); //print the input value on the serial monitor
  Serial.print("\t output = "); 
  Serial.println(outputValue); //print the output value on the serial monitor
  delay(2); // wait 2 ms before next loop for analog-to-digital converter to settle after last reading
}