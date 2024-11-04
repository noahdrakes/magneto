#include <VibrationMotor.h>

const int vibMotorPin = 9;
int fsrPin = 0;
int fsrReading;

// VibrationMotor myVibrationMotor(motorPin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  fsrReading = analogRead(fsrPin);

  Serial.println(fsrReading);

  if (fsrReading < 10){ //no pressure 
      analogWrite(vibMotorPin, 255); // 255 is full speed
      delay(500);                // Run motor for 1 second
      analogWrite(vibMotorPin, 0);
      delay(500); 
  }
  else if(fsrReading < 200){ //light touch
      analogWrite(vibMotorPin, 255); // 255 is full speed
      delay(250);                // Run motor for 1 second
      analogWrite(vibMotorPin, 0);
      delay(250); 
  }
  else if (fsrReading < 500) { //light squeeze
      analogWrite(vibMotorPin, 255); // 255 is full speed
      delay(125);                // Run motor for 1 second
      analogWrite(vibMotorPin, 0);
      delay(125); 
  }
  else if (fsrReading < 800) { //medium squeeze
    analogWrite(vibMotorPin, 255); // 255 is full speed
      delay(62);                // Run motor for 1 second
      analogWrite(vibMotorPin, 0);
      delay(62); 
  }
  else { //big squeeze
    analogWrite(vibMotorPin, 255); // 255 is full speed
      delay(10);                // Run motor for 1 second
      analogWrite(vibMotorPin, 0);
      delay(10); 
  }
  delay(1000);


}
