#include <Wire.h>

// Motor connections
int enA = 9;
int in1 = 8;
int in2 = 7;


void setup() {
  Wire.begin(0x8); // Setting Arduino as slave and joining I2C bus with address 8.
  Wire.onReceive(Action); // Calling ActionFunction, whenever data is received.
  
	// Set the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	
	// Turn off motor - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	
}

void loop() {
	StartSpray();
	delay(1000);
	StopSpray();
	delay(1000);
}

void Action() {
  while(Wire.available()) {
    char a = Wire.read();
  }
  if (a == "1") {
    StartSpray();
  }
  else if (a == "0") {
    StopSpray()
  }
void StartSpray() {
	analogWrite(enA, 255); //MaxSpeed

	// Turn on motor
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	
 }

// This function lets you control speed of the motors
void StopSpray() {
	// Turn on motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	
	
	// Now turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

