// include the servo library

#include <Servo.h>

// make a new servo object

Servo servo;

// Have 3 ultrasonic distance sensors, the main one on the front is contorlled by pot meter, while the other two aren't - this is because of object disruptions (ex. placing on a table might false fire them)

//define the ultrasonic distance sensor pins

//ultrasonic sensor 1

const int trigPin1 = 9;

const int echoPin1 = 8;

//ultrasonic sensor 2

const int trigPin2 = 2;

const int echoPin2 = 3;

//ultrasonic sensor 3

const int trigPin3 = 5;

const int echoPin3 = 4;

// define variables

//ultrasonic sensor 1

long duration1;

int distance1;

//ultrasonic sensor 2

long duration2;

int distance2;

//ultrasonic sensor 3

long duration3;

int distance3;

bool detected = false; // initially hand is not detected 

const int buzzerPin = 11;

const int ledPin = LED_BUILTIN;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {

  Serial.begin(9600); //use serial port with a baud rate of 9600

  pinMode(ledPin, OUTPUT);

  pinMode(buzzerPin, OUTPUT);  //set buzzerPin as OUTPUT

  servo.attach(7); //attach servo to pin 7

  servo.write(0);

  delay(100);

  // For each of the 3 ultrasonic dist sensors, set the trigPin as an Output and sets the echoPin as an Input

  pinMode(trigPin1, OUTPUT);

  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);

  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);

  pinMode(echoPin3, INPUT);

}

void loop() {

  servoReady();

  runFunctionality();

  // Prints the distance on the Serial Monitor for debugging

  //  Serial.print("Distance: ");

  //  Serial.println(distance);

}

void servoReady() {

  // Servo code

  // Clears the trigPin

  digitalWrite(trigPin1, LOW);

  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds

  digitalWrite(trigPin1, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin1, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds

  duration1 = pulseIn(echoPin1, HIGH);

  // Calculating the distance

  distance1 = duration1 * 0.034 / 2;

  // Repeat for the second ultrasonic distance sensor

  digitalWrite(trigPin2, LOW);

  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds

  digitalWrite(trigPin2, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin2, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds

  duration2 = pulseIn(echoPin2, HIGH);

  // Calculating the distance

  distance2 = duration2 * 0.034 / 2;

  

   // Repeat for the third ultrasonic distance sensor

  digitalWrite(trigPin3, LOW);

  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds

  digitalWrite(trigPin3, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin3, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds

  duration3 = pulseIn(echoPin3, HIGH);

  // Calculating the distance

  distance3 = duration3 * 0.034 / 2;

}

void runFunctionality() {

  if (distance1 <= 20 || distance2 <= 6 || distance3 <= 6) // Change distance according to Ultrasonic Sensor Placement

  {

    detected = true;

    digitalWrite(buzzerPin, HIGH);

    digitalWrite(ledPin, HIGH);

    servo.write(90);

    delay(200);

  } else {

    // turn off buzzer when nothing is detected

    digitalWrite(buzzerPin, LOW);

    digitalWrite(ledPin, LOW);

    servo.write(0);

  }

}
