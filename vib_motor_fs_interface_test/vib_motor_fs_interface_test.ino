#include <VibrationMotor.h>

const int vibMotorPin = 6;
const int vibMotorPin1 = 5;
int fsrPin = 0;
int fsrPin1 = 1;
int fsrReading;
int fsrReading1;

// VibrationMotor myVibrationMotor(motorPin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(vibMotorPin, OUTPUT);
  pinMode(vibMotorPin1, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  fsrReading = analogRead(fsrPin);
  fsrReading1 = analogRead(fsrPin1);

  

  // Serial.println(force);
  Serial.print("fsr 1: ");
  Serial.println(fsrReading);

  // Serial.print("lock in ");

  Serial.print("fsr 2: ");
  Serial.println(fsrReading1);

  fsrReading = map(fsrReading, 0, 850, 0, 1023);
  fsrReading1 = map(fsrReading1, 0, 850, 0, 1023);

  if (fsrReading1 >= 150){
    Serial.println("-----------------------------------");
  }

  // Serial.println(output);
  

  // if (fsrReading < 10){ //no pressure 
  //     // analogWrite(vibMotorPin, 255); // 255 is full speed
  //     // delay(500);                // Run motor for 1 second
  //     // analogWrite(vibMotorPin, 0);
  //     // delay(500); 
  // }
  // else if(fsrReading < 200){ //light touch
  //     analogWrite(vibMotorPin, 255); // 255 is full speed
  //     delay(250);                // Run motor for 1 second
  //     analogWrite(vibMotorPin, 0);
  //     delay(250); 
  // }
  // else if (fsrReading < 500) { //light squeeze
  //     analogWrite(vibMotorPin, 255); // 255 is full speed
  //     delay(125);                // Run motor for 1 second
  //     analogWrite(vibMotorPin, 0);
  //     delay(125); 
  // }
  // else if (fsrReading < 800) { //medium squeeze
  //   analogWrite(vibMotorPin, 255); // 255 is full speed
  //     delay(62);                // Run motor for 1 second
  //     analogWrite(vibMotorPin, 0);
  //     delay(62); 
  // }
  // else { //big squeeze
  //   analogWrite(vibMotorPin, 255); // 255 is full speed
  //     delay(10);                // Run motor for 1 second
  //     analogWrite(vibMotorPin, 0);
  //     delay(10); 
  // }
  // delay(1000);

  if (fsrReading >= 0 && fsrReading < 80){ //no pressure 
      // analogWrite(vibMotorPin, 255); // 255 is full speed
      // delay(500);                // Run motor for 1 second
      // analogWrite(vibMotorPin, 0);
      // delay(500); 
      // Serial.println("we are here");
      analogWrite(vibMotorPin, 0);
  }
  else if(fsrReading >= 80 && fsrReading < 200){ //light touch
      // analogWrite(vibMotorPin, 45); // 255 is full speed

      analogWrite(vibMotorPin, 255); // 255 is full speed
      delay(500);                // Run motor for 1 second
      analogWrite(vibMotorPin, 0);
      delay(500); 
  }
  else if (fsrReading >= 200 && fsrReading < 500) { //light squeeze
      // analogWrite(vibMotorPin, 85);

      analogWrite(vibMotorPin, 255); // 255 is full speed
      delay(125);                // Run motor for 1 second
      analogWrite(vibMotorPin, 0);
      delay(125); 
  }
  else if (fsrReading >= 500 && fsrReading < 800) { //medium squeeze
    // analogWrite(vibMotorPin, 125); // 255 is full speed

      analogWrite(vibMotorPin, 255); // 255 is full speed
      delay(62);                // Run motor for 1 second
      analogWrite(vibMotorPin, 0);
      delay(62); 
  }
  else { //big squeeze
    // analogWrite(vibMotorPin, 200); // 255 is full speed

      analogWrite(vibMotorPin, 255); // 255 is full speed
      delay(10);                // Run motor for 1 second
      analogWrite(vibMotorPin, 0);
      delay(10); 
  }


  if (fsrReading1 >= 0 && fsrReading1 < 80){ //no pressure 
      // analogWrite(vibMotorPin, 255); // 255 is full speed
      // delay(500);                // Run motor for 1 second
      // analogWrite(vibMotorPin, 0);
      // delay(500); 
      // Serial.println("here");
      analogWrite(vibMotorPin1, 0);
  }
  else if(fsrReading1 >= 80 && fsrReading1 < 200){ //light touch
      // analogWrite(vibMotorPin, 45); // 255 is full speed

      analogWrite(vibMotorPin1, 100); // 255 is full speed
      delay(500);                // Run motor for 1 second
      analogWrite(vibMotorPin1, 0);
      delay(500); 
  }
  else if (fsrReading1 >= 200 && fsrReading1 < 500) { //light squeeze
      // analogWrite(vibMotorPin, 85);

      analogWrite(vibMotorPin1, 100); // 255 is full speed
      delay(125);                // Run motor for 1 second
      analogWrite(vibMotorPin1, 0);
      delay(125); 
  }
  else if (fsrReading1 >= 500 && fsrReading1 < 800) { //medium squeeze
    // analogWrite(vibMotorPin, 125); // 255 is full speed

      analogWrite(vibMotorPin1, 100); // 255 is full speed
      delay(62);                // Run motor for 1 second
      analogWrite(vibMotorPin1, 0);
      delay(62); 
  }
  else { //big squeeze
    // analogWrite(vibMotorPin, 200); // 255 is full speed

      analogWrite(vibMotorPin1, 100); // 255 is full speed
      delay(10);                // Run motor for 1 second
      analogWrite(vibMotorPin1, 0);
      delay(10); 
  }


}
