// BUTTON DATA PINS - INPUT
const int buttonGreenPin = 2;    // green button
const int buttonRedPin = 3;       // red button
const int buttonYellowPin = 4;    // yellow button

// LED PINS - OUTPUT
const int ledGreenPin = 8;       // green led
const int ledRedPin = 10;         // red led
const int ledYellowPin = 9;     // yellow led

// Counter for current mood, increment/decrement
int counter = 0;

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
 
  // initialize the LED as an output
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledRedPin, OUTPUT);
  pinMode(ledYellowPin, OUTPUT);
 
  // initialize serial communication
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin
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
        greenLEDOn(); // turn on green led (see respective defined function)
        counter += 1;
      }
      delay(50); // Delay a little bit to avoid bouncing
    }
    // save the current state as the last state, for next time through the loop
    lastButtonStateGreen = buttonStateGreen;
  }

  // scope block for yellow
  {
    // compare the buttonStates to the previous states
    if ((buttonStateYellow != lastButtonStateYellow)) {
      // if the state has changed, increment the counter
      if (buttonStateYellow == HIGH) {
        // if the current state is HIGH then the button went from off to on:
        yellowLEDOn(); // turns yellow led on (see the respective defined function)
        //counter+=0; don't need this because yellow literally does nothing
      }
      delay(50);
    }
    // save the current state as the last state, for next time through the loop
    lastButtonStateYellow = buttonStateYellow;
  }

  //scope block for red
  {
    // compare the buttonStates to the previous states
    if ((buttonStateRed != lastButtonStateRed)) {
      // if the state has changed, increment the counter
      if (buttonStateRed == HIGH) {
        // if the current state is HIGH then the button went from off to on:
        redLEDOn(); // turns red led on (see respective defined function)
        counter -= 1;
      }
      delay(50);
    }
    // save the current state as the last state, for next time through the loop
    lastButtonStateRed = buttonStateRed;
  }

  // Determine which LED should be lit based on mood counter
  if (counter > 0) {
    greenLEDOn();
  } else if (counter < 0) {
    redLEDOn();
  } else {
    yellowLEDOn();
  }
    Serial.println(counter); // debug print current counter
}

// turn on red LED
void redLEDOn() {
  digitalWrite(ledGreenPin, LOW);
  digitalWrite(ledYellowPin, LOW);
  digitalWrite(ledRedPin, HIGH);
}

// turn on green LED
void greenLEDOn() {
  digitalWrite(ledRedPin, LOW);
  digitalWrite(ledYellowPin, LOW);
  digitalWrite(ledGreenPin, HIGH);
}

// turn on yellow LED
void yellowLEDOn() {
  digitalWrite(ledGreenPin, LOW);
  digitalWrite(ledRedPin, LOW);
  digitalWrite(ledYellowPin, HIGH);
}
