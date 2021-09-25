// C++ code
//
#define LED2 2
#define LED1 1
void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop()
{
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED2, HIGH);
  digitalWrite(LED1, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}