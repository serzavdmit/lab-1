const int ledPin = 13; 
String inputString = ""; 
boolean stringComplete = false; 
int number = 0;
void setup() 
{
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT);
}
void loop() 
{
  if (stringComplete) 
  { 
    if (inputString.startsWith("AT+")) 
    { 
      inputString.remove(0, 3); 
      number = inputString.toInt(); 
      if (number % 10 == 0) 
      { 
        digitalWrite(ledPin, HIGH); 
      } else 
      {
        digitalWrite(ledPin, LOW); 
      }
    }
    inputString = ""; 
    stringComplete = false;
  }
}
void serialEvent() 
{
  while (Serial.available()) 
  {
    char inChar = (char)Serial.read(); 
    inputString += inChar; 
    if (inChar == '\n') 
    { 
      stringComplete = true;
    }
  }
}