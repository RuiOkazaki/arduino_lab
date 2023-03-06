int SWITCH_SOCKET = 2;
int count = 0;

void setup()
{
  pinMode(SWITCH_SOCKET, INPUT);
  Serial.begin(9600);
}
void loop()
{
  int switchState = digitalRead(SWITCH_SOCKET);
  if (switchState == 1)
  {
    count++;
  }
  Serial.println(count);
}