int VOLUME_SOCKET = 0;
int DIGITAL_VOLUME_SOCKET = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(DIGITAL_VOLUME_SOCKET, INPUT);
}

void loop()
{
  int analog_value;
  int digital_value;
  float input_voltage;

  digital_value = digitalRead(DIGITAL_VOLUME_SOCKET);
  analog_value = analogRead(VOLUME_SOCKET);

  input_voltage = analog_value * (5.0 / 1023.0);

  Serial.println("");
  Serial.println(digital_value);
  Serial.println(analog_value);

  Serial.print(": ");
  Serial.print(input_voltage);
  Serial.println("V");

  delay(1000);
}