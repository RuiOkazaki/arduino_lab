int SWITCH_SOCKET = 2;

void setup()
{
  pinMode(SWITCH_SOCKET, INPUT);
  Serial.begin(9600);
}
void loop()
{
  int switchState = digitalRead(SWITCH_SOCKET);
  Serial.println(switchState);
  delay(100);
}