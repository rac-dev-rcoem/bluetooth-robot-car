// Define motor control pins
const int motorPin1 = 11;  // IN1
const int motorPin2 = 10;  // IN2
const int motorPin3 = 9;   // IN3
const int motorPin4 = 6;   // IN4

char command = ' ';

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 bps

  // Initialize motor control pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) { // Check if data is available to read
    command = Serial.read();    // Read the incoming data

    switch (command) {
      case 'F':  // Move forward
        moveForward();
        break;
        
      case 'B':  // Move backward
        moveBackward();
        break;
        
      case 'L':  // Turn left
        turnLeft();
        break;
        
      case 'R':  // Turn right
        turnRight();
        break;
        
      case 'S':  // Stop
        stopMotors();
        break;
    }
  }
}

// Function to move forward
void moveForward() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}

// Function to move backward
void moveBackward() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}

// Function to turn left
void turnLeft() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}

// Function to turn right
void turnRight() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}

// Function to stop the motors
void stopMotors() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}