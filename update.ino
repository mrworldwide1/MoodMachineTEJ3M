// BUTTON DATA PINS - INPUTS
const int  buttonGreenPin = 2;    // green button
const int buttonRedPin = 3;       // red button
const int buttonYellowPin = 4;    // yellow button

// LED PINS - OUTPUT
const int ledGreenPin = 8;       // green led
const int ledRedPin = 9;         // red led
const int ledYellowPin = 10;     // yellow led

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses

// GREEN BUTTON STATE CHECK
int buttonStateGreen = 0;         // current state of the green button
int lastButtonStateGreen = 0;     // previous state of the green button

// RED BUTTON STATE CHECK
int buttonStateRed = 0;           // current state of the red button
int lastButtonStateRed = 0;       // previous state of the red button


// YELLOW BUTTON STATE CHECK
int buttonStateYellow = 0;           // current state of the yellow button
int lastButtonStateYellow = 0;       // previous state of the yellow button


void setup() {
  // initialize the button pins as inputs
  pinMode(buttonGreenPin, INPUT);
  pinMode(buttonRedPin, INPUT);
  pinMode(buttonYellowPin, INPUT);
 
  // initialize the LED as an output:
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledRedPin, OUTPUT);
  pinMode(ledYellowPin, OUTPUT);
 
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  buttonStateGreen = digitalRead(buttonGreenPin);
  buttonStateRed = digitalRead(buttonRedPin);
  buttonStateYellow = digitalRead(buttonYellowPin);

  // seperate into scopes using {}

  // scope block for green
  {
      // compare the buttonStates to the previous states
    if ((buttonStateGreen != lastButtonStateGreen)) {
      // if the state has changed, increment the counter
      if (buttonStateGreen == HIGH) {
        // if the current state is HIGH then the button went from off to on:
        digitalWrite(ledRedPin, LOW);
        digitalWrite(ledYellowPin, LOW);
        digitalWrite(ledGreenPin, HIGH); // turn on led
      }
      // Delay a little bit to avoid bouncing
      delay(50);
    }
    // save the current state as the last state, for next time through the loop
    lastButtonStateGreen = buttonStateGreen;
  }

  // scope block for red
  {
      // compare the buttonStates to the previous states
    if ((buttonStateRed != lastButtonStateRed)) {
      // if the state has changed, increment the counter
      if (buttonStateRed == HIGH) {
        // if the current state is HIGH then the button went from off to on:
        digitalWrite(ledGreenPin, LOW);
        digitalWrite(ledYellowPin, LOW);
        digitalWrite(ledRedPin, HIGH); // turn on led
      }
      delay(50);
    }
    // save the current state as the last state, for next time through the loop
    lastButtonStateRed = buttonStateRed;
  }

  // scope for yellow
  {
      // compare the buttonStates to the previous states
    if ((buttonStateYellow != lastButtonStateYellow)) {
      // if the state has changed, increment the counter
      if (buttonStateYellow == HIGH) {
        // if the current state is HIGH then the button went from off to on:
        digitalWrite(ledGreenPin, LOW);
        digitalWrite(ledRedPin, LOW);
        digitalWrite(ledYellowPin, HIGH); // turn on led
      }
      delay(50);
    }
    // save the current state as the last state, for next time through the loop
    lastButtonStateYellow = buttonStateYellow;
  
  }
  
}
