#define CONTROLED_LED_PIN 13
#define BOTTON_INPUT_PIN 2
#define SENSE_DELAY 50

int presentBottonState = 0;
int lastBottonState = 0;

void setup() 
{
  // Code that run only once to do the inital things
  pinMode(CONTROLED_LED_PIN, OUTPUT);                    // (These two) Init the pin-modes
  pinMode(BOTTON_INPUT_PIN, INPUT);

  digitalWrite(CONTROLED_LED_PIN, LOW);                  // Give the LED an inital state 
}

void loop() 
{
  // Code that run once and once again until the board is out of energy

  lastBottonState = presentBottonState;                 // Take a record of the LAST state of the botton, 
                                                        // that use to tell when the botton is pushed down or freed up
  presentBottonState = digitalRead(BOTTON_INPUT_PIN);   // Read from botton pin
  
  switch (presentBottonState - lastBottonState)         // If the botton is pushed down, that result will be 1
  {                                                     // If the botton is freed up, that result will be -1
    case 1:                                             // If you do nothing, that will be 0...
      digitalWrite(CONTROLED_LED_PIN, HIGH);            // Handle the situation of pushing the botton
      break;
    case -1:
      digitalWrite(CONTROLED_LED_PIN, LOW);             // Handle the situation of freeing the botton
      break;
    case 0:
      break;                                            // Handle the situation of nothing hapened = =
    default:                                            // Handle the unexpected situation (...)
      break;
  }
  
  delay(SENSE_DELAY);
}
