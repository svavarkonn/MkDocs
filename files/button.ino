#define BUTTON_PIN 29
#define LED_PIN 26
bool status = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  status = digitalRead(BUTTON_PIN);
  Serial.println(status);
  if (status == 1) {
    digitalWrite(LED_PIN, LOW);
  } else {
    digitalWrite(LED_PIN, HIGH);
  }
  delay(100);
}