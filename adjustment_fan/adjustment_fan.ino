const int INCREMENT_INPUT_SOCKET = 2;
const int DECREMENT_INPUT_SOCKET = 3;
const int SHUTDOWN_INPUT_SOCKET = 4;

const int FAN_OUTPUT_SOCKET = 5;

int powerValue = 50;

void setup()
{
  Serial.begin(9600);
  pinMode(INCREMENT_INPUT_SOCKET, INPUT);
  pinMode(DECREMENT_INPUT_SOCKET, INPUT);
  pinMode(SHUTDOWN_INPUT_SOCKET, INPUT);
  pinMode(FAN_OUTPUT_SOCKET, OUTPUT);
}

void loop()
{
  int incrementValue = digitalRead(INCREMENT_INPUT_SOCKET);
  int decrementValue = digitalRead(DECREMENT_INPUT_SOCKET);
  int shutdownValue = digitalRead(SHUTDOWN_INPUT_SOCKET);

  if (incrementValue == HIGH && powerValue < 250)
  {
    incrementPowerValue();
  }

  if (decrementValue == HIGH && powerValue > 0)
  {
    decrementPowerValue();
  }

  if (shutdownValue == HIGH)
  {
    shutdownPowerValue();
  }

  analogWrite(FAN_OUTPUT_SOCKET, powerValue);

  delay(100);
}

void incrementPowerValue()
{
  powerValue += 10;
  Serial.print("Incrementing power value: ");
  Serial.println(powerValue);
}

void decrementPowerValue()
{
  powerValue -= 10;
  Serial.print("Decrementing power value: ");
  Serial.println(powerValue);
}

void shutdownPowerValue()
{
  powerValue = 0;
  Serial.print("Shutting down power value: ");
  Serial.println(powerValue);
}