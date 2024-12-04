//#include <VibrationMotor.h>/

const int vibMotorPin1 = 6;
const int vibMotorPin2 = 5;

const int encA = 8;
const int encB = 9;


int fsrPin1 = 0;
int fsrPin2 = 1;
int fsrReading1;
int fsrReading2;

int counter = 0; 
int aState;
int aLastState;  

// VibrationMotor myVibrationMotor(motorPin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(vibMotorPin1, OUTPUT);
  pinMode(vibMotorPin2, OUTPUT);
  
  pinMode (encA,INPUT);
  pinMode (encB,INPUT);

  aLastState = digitalRead(encA);   

  

}

void loop() {

  aState = digitalRead(encA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(encB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("Position: ");
     Serial.println(counter);
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state


  
  // put your main code here, to run repeatedly:
  fsrReading1 = analogRead(fsrPin1);
  fsrReading2 = analogRead(fsrPin2);

  

  // Serial.println(force);
 

  // Serial.print("lock in ");

  

  fsrReading1 = map(fsrReading1, 0, 850, 0, 1023);
  fsrReading2 = map(fsrReading2, 0, 850, 0, 1023);


  if (fsrReading1 > fsrReading2){

    for (int i = 0; i < 2; i++){
      if (fsrReading1 >= 0 && fsrReading1 < 60){ //no pressure 
          analogWrite(vibMotorPin1, 0);
      }
      else if(fsrReading1 >= 60 && fsrReading1 < 200){ //light touch
          Serial.print("fsr 1: ");
          Serial.println(fsrReading1);
    
          analogWrite(vibMotorPin1, 255); // 255 is full speed
          delay(125);                // Run motor for 1 second
          analogWrite(vibMotorPin1, 0);
          delay(125); 
      }
      else if (fsrReading1 >= 200 && fsrReading1 < 500) { //light squeeze
          Serial.print("fsr 1: ");
          Serial.println(fsrReading1);
    
          analogWrite(vibMotorPin1, 255); // 255 is full speed
          delay(62);                // Run motor for 1 second
          analogWrite(vibMotorPin1, 0);
          delay(62); 
      }
      else if (fsrReading1 >= 500 && fsrReading1 < 800) { //medium squeeze
          Serial.print("fsr 1: ");
          Serial.println(fsrReading1);
    
          analogWrite(vibMotorPin1, 255); // 255 is full speed
          delay(31);                // Run motor for 1 second
          analogWrite(vibMotorPin1, 0);
          delay(31); 
      }
      else { //big squeeze
          Serial.print("fsr 1: ");
          Serial.println(fsrReading1);
    
          analogWrite(vibMotorPin1, 255); // 255 is full speed
          delay(10);                // Run motor for 1 second
          analogWrite(vibMotorPin1, 0);
          delay(10); 
      }
    }
  } else {

    for (int i = 0; i < 2; i++){
      if (fsrReading2 >= 0 && fsrReading2 < 60){ //no pressure 
          analogWrite(vibMotorPin2, 0);
      }
      else if(fsrReading2 >= 60 && fsrReading2 < 200){ //light touch
          Serial.print("fsr 2: ");
          Serial.println(fsrReading2);
    
          analogWrite(vibMotorPin2, 100); // 255 is full speed
          delay(125);                // Run motor for 1 second
          analogWrite(vibMotorPin2, 0);
          delay(125); 
      }
      else if (fsrReading2 >= 200 && fsrReading2 < 500) { //light squeeze
          Serial.print("fsr 2: ");
          Serial.println(fsrReading2);
    
          analogWrite(vibMotorPin2, 100); // 255 is full speed
          delay(62);                // Run motor for 1 second
          analogWrite(vibMotorPin2, 0);
          delay(62); 
      }
      else if (fsrReading2 >= 500 && fsrReading2 < 800) { //medium squeeze
          Serial.print("fsr 2: ");
          Serial.println(fsrReading2);
    
          analogWrite(vibMotorPin2, 100); // 255 is full speed
          delay(32);                // Run motor for 1 second
          analogWrite(vibMotorPin2, 0);
          delay(32); 
      }
      else { //big squeeze
          Serial.print("fsr 2: ");
          Serial.println(fsrReading2);
    
          analogWrite(vibMotorPin2, 100); // 255 is full speed
          delay(10);                // Run motor for 1 second
          analogWrite(vibMotorPin2, 0);
          delay(10); 
      }
    }
  }




  


}
