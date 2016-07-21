#define LED1_PIN 12
#define LED2_PIN 8
#define LED3_PIN 7
#define DELAY 50
#define LED_AMOUNT 3

const int LEDadress[] = {LED1_PIN, LED2_PIN, LED3_PIN};
int LEDnum = 0;

void setup() 
{
  for (int i = 0; i < LED_AMOUNT; i++)
  {
    pinMode(LEDadress[i], OUTPUT);
  }
}

void loop() 
{
  digitalWrite(LEDadress[LEDnum % LED_AMOUNT], HIGH);
  delay(DELAY);
  digitalWrite(LEDadress[LEDnum % LED_AMOUNT], LOW);
  delay(DELAY);
  LEDnum++;
}
