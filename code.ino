const int tempPin = A0;
const int motorPin = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
}

void loop()
{
  int reading = analogRead(tempPin);

  float voltage = reading * (5.0 / 1023.0);

  // TMP36 conversion
  float temperature = (voltage - 0.5) * 100.0;

  int pwmValue;

  if (temperature < 27)
  {
    pwmValue = 0;
  }
  else if (temperature >= 40)
  {
    pwmValue = 255;
  }
  else
  {
    pwmValue = map((int)temperature, 27, 40, 0, 255);
  }

  analogWrite(motorPin, pwmValue);

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print("C, PWM: ");
  Serial.println(pwmValue);

  delay(500);
}