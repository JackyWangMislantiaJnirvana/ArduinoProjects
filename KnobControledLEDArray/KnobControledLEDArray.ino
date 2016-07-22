/*
Knob Controled LED Array
get voltage value from a analog pin, and transfer it to the number of lit LEDs
the lower/higer(you can change it) the voltage is, the more LED will be lit
*/ 

// Define some const values
#define LED1_PIN 2
#define LED2_PIN 3
#define LED3_PIN 4
#define LED4_PIN 5
#define LED5_PIN 6
#define LED6_PIN 7
#define ANALOG_INPUT_PIN A0
#define LED_AMOUNT 6
#define SENSE_DELAY 10
#define ON LOW                                                                                // In this circuit, LOW sigle on the pin makes the LED ON
#define OFF HIGH                                                                              // In this circuit, HIGH sigle on the pin makes the LED OFF

// Init some values
const int LEDPins[LED_AMOUNT] = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN, LED5_PIN, LED6_PIN}; // A const array that discripe the pins
int analogValue = 0;                                                                      
int openLEDAmount = 0;

void setup() 
{
  // This function will run only once when the power is on in order to do the inital things
  for(int i = 0 ;i < LED_AMOUNT; i++)                                                        // Set pin-mode of LED pins to OUTPUT
  {
    pinMode(LEDPins[i], OUTPUT);
  }
  
  pinMode(ANALOG_INPUT_PIN, INPUT);                                                          // Set pin-mode of analog pin to INPUT
  
}

void loop() 
{
  // This function will run over and over again until the board is out of energy
  for(int i = 0; i < LED_AMOUNT; i++)                                                        // Turn OFF all the LEDs
  {
    digitalWrite(LEDPins[i], HIGH);
  }

  analogValue = analogRead(ANALOG_INPUT_PIN);                                                // Read from the analog pin to tell the position of the knob
  openLEDAmount = map(analogValue, 0, 1023, LED_AMOUNT, 0);                                  // Convert the value read from the pin(0-1023) to the amount of LEDs to turn on
  
  for(int i = 0;i < openLEDAmount; i++)                                                      // Turn on the selected LEDs
  {
    digitalWrite(LEDPins[i], LOW);
  }

delay(SENSE_DELAY);                                                                          // Take a break!

}
