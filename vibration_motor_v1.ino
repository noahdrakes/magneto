#include <VibrationMotor.h>

const int motorPin = 5;
int fsrPin = 0;
int fsrReading;

VibrationMotor myVibrationMotor(motorPin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  fsrReading = analogRead(fsrPin);
  if (fsrReading < 10){ //no pressure 

  }
  else if(fsrReading < 200){ //light touch
    //myVibrationMotor.pulse(1); //pulses once
    myVibrationMotor.on(1); //turns the motor on 
  }
  else if (fsrReading < 500) { //light squeeze

  }
  else if (fsrReading < 800) { //medium squeeze

  }
  else { //big squeeze

  }
  delay(1000);


}
