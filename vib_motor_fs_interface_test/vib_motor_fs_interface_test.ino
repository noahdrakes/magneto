//#include <VibrationMotor.h>/
#include <string.h>

#define VIB_MOTOR_MAX_PWM                       125
#define FORCE_SENSOR_NO_CONTACT_MAX_THRESHOLD   60



volatile int vibMotorPin1 = 6;
volatile int vibMotorPin2 = 5;

const uint8_t encA = 2;
const uint8_t encB = 3;

volatile int encoderCount = 0;
volatile int aState;
volatile int aLastState; 

// false = [0 to 14]
// true = [15 to 29]
volatile uint8_t encoder_side = 0;
volatile uint8_t last_encoder_side = 0;

enum ENCODER_SIDE{
  ENCODER_FIRST_HALF,
  ENCODER_SECOND_HALF
};


int fsrPin1 = 0;
int fsrPin2 = 1;
int fsrReading1;
int fsrReading2; 

// VibrationMotor myVibrationMotor(motorPin);
using namespace std;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(vibMotorPin1, OUTPUT);
  pinMode(vibMotorPin2, OUTPUT);
  
  pinMode (encA,INPUT);
  pinMode (encB,INPUT);

  aLastState = digitalRead(encA);   

  attachInterrupt(digitalPinToInterrupt(encA),updateState, CHANGE );

  clearSerialMon();

  calibrateEncoder();
}

void clearSerialMon(){
  for (int i = 0; i < 5; i++){
    Serial.println(" ");
  }

  Serial.println("=============================");
}

void calibrateEncoder(){

  while(1){
    Serial.println("Catheter Encoder Calibration !");
    Serial.println("Twist catheter so that each forse sensor is pointing in the right and left direction");
    Serial.println("Type 'y' and Press [ENTER] in the Serial Monitor when finished");

    while(Serial.available() <= 0 ){}

    char string = Serial.read();
    if(string == 'y'){
      Serial.println("Encoder Calibration Finished !");
      break;
    } else {
      Serial.println("Invalid character. Try again");
    }
    encoderCount = 0;
  }
    
}

void updateEncoderPos(){
  aState = digitalRead(encA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(encB) != aState) { 
       encoderCount++;
     } else {
       encoderCount--;
     }

     if (encoderCount == -1){
      encoderCount = 29;
     } else if (encoderCount == 30){
      encoderCount = 0;
     }
    
     Serial.print("ENCODER POS: ");
     Serial.println(encoderCount);
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state


}

// switch vib motor based on catheter encoder position
void updateVibMotors(){
  if (encoderCount >=0 && encoderCount <15){
    encoder_side = ENCODER_FIRST_HALF;
  } else {
    encoder_side = ENCODER_SECOND_HALF;
  }

  if (encoder_side != last_encoder_side){
    uint8_t temp = vibMotorPin1;
    vibMotorPin1 = vibMotorPin2; 
    vibMotorPin2 = temp;
    Serial.println("here");
  } 

  last_encoder_side = encoder_side;
}


void updateState(){
  updateEncoderPos();
  updateVibMotors();
}

void loop() {

  fsrReading1 = analogRead(fsrPin1);
  fsrReading2 = analogRead(fsrPin2);

  fsrReading1 = map(fsrReading1, 0, 850, 0, 1023);
  fsrReading2 = map(fsrReading2, 0, 850, 0, 1023);

//  fsrReading1=0;///


  if (fsrReading1 > fsrReading2){

    for (int i = 0; i < 2; i++){
      if (fsrReading1 >= 0 && fsrReading1 < FORCE_SENSOR_NO_CONTACT_MAX_THRESHOLD){ //no pressure 
          analogWrite(vibMotorPin1, 0);
      }
      else if(fsrReading1 >= FORCE_SENSOR_NO_CONTACT_MAX_THRESHOLD && fsrReading1 < 200){ //light touch
          Serial.print("fsr 1: ");
          Serial.println(fsrReading1);
    
          analogWrite(vibMotorPin1, VIB_MOTOR_MAX_PWM); // 255 is full speed
          delay(125);                // Run motor for 1 second
          analogWrite(vibMotorPin1, 0);
          delay(125); 
      }
      else if (fsrReading1 >= 200 && fsrReading1 < 500) { //light squeeze
          Serial.print("fsr 1: ");
          Serial.println(fsrReading1);
    
          analogWrite(vibMotorPin1, VIB_MOTOR_MAX_PWM); // 255 is full speed
          delay(62);                // Run motor for 1 second
          analogWrite(vibMotorPin1, 0);
          delay(62); 
      }
      else if (fsrReading1 >= 500 && fsrReading1 < 800) { //medium squeeze
          Serial.print("fsr 1: ");
          Serial.println(fsrReading1);
    
          analogWrite(vibMotorPin1, VIB_MOTOR_MAX_PWM); // 255 is full speed
          delay(31);                // Run motor for 1 second
          analogWrite(vibMotorPin1, 0);
          delay(31); 
      }
      else { //big squeeze
          Serial.print("fsr 1: ");
          Serial.println(fsrReading1);
    
          analogWrite(vibMotorPin1, VIB_MOTOR_MAX_PWM); // 255 is full speed
          delay(10);                // Run motor for 1 second
          analogWrite(vibMotorPin1, 0);
          delay(10); 
      }
    }
  } else {

    for (int i = 0; i < 2; i++){
      if (fsrReading2 >= 0 && fsrReading2 < FORCE_SENSOR_NO_CONTACT_MAX_THRESHOLD){ //no pressure 
          analogWrite(vibMotorPin2, 0);
      }
      else if(fsrReading2 >= FORCE_SENSOR_NO_CONTACT_MAX_THRESHOLD && fsrReading2 < 200){ //light touch
          Serial.print("fsr 2: ");
          Serial.println(fsrReading2);
    
          analogWrite(vibMotorPin2, VIB_MOTOR_MAX_PWM); // 255 is full speed
          delay(125);                // Run motor for 1 second
          analogWrite(vibMotorPin2, 0);
          delay(125); 
      }
      else if (fsrReading2 >= 200 && fsrReading2 < 500) { //light squeeze
          Serial.print("fsr 2: ");
          Serial.println(fsrReading2);
    
          analogWrite(vibMotorPin2, VIB_MOTOR_MAX_PWM); // 255 is full speed
          delay(62);                // Run motor for 1 second
          analogWrite(vibMotorPin2, 0);
          delay(62); 
      }
      else if (fsrReading2 >= 500 && fsrReading2 < 800) { //medium squeeze
          Serial.print("fsr 2: ");
          Serial.println(fsrReading2);
    
          analogWrite(vibMotorPin2, VIB_MOTOR_MAX_PWM); // 255 is full speed
          delay(32);                // Run motor for 1 second
          analogWrite(vibMotorPin2, 0);
          delay(32); 
      }
      else { //big squeeze
          Serial.print("fsr 2: ");
          Serial.println(fsrReading2);
    
          analogWrite(vibMotorPin2, VIB_MOTOR_MAX_PWM); // 255 is full speed
          delay(10);                // Run motor for 1 second
          analogWrite(vibMotorPin2, 0);
          delay(10); 
      }
    }
  }




  


}
