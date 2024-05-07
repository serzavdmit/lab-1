const String command = "AT+";
const int pause = 100;
int count = 1;
void setup() 
{
 Serial.begin(9600);
}
void loop() 
{
  Serial.print(command);
  Serial.print(count++);
  Serial.print("\r\n");
  delay(pause);
}