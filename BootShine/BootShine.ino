#include<Stepper>

unsigned long previousMilliseconds = 0; 

int limitSwitchPin = 6;
//Each Stepper Motor takes 4 pins 
int rotationalStepperPin1 = 7, rotationalStepperPin2 = 6, rotationalStepperPin3 = 5, rotatioanlStepperPin4 = 4; 
int extrusionStepperPin1 = 3, extrusionStepperPin2 = 2, extrusionStepperPin3 = 1, extrusionStepperPin4 = 0; 
int UV_RelayPin = 12; 
int toggleOnButtonPin = 11; 
int toggleEmergencyStopPin = 10;

const int stepsPerRevolution = 200; //Depends on stepper motor 
const int mmToOpen = 0; //TBD 
const int mmToClose = 0; //TBD 


Stepper rotationalStepperMotor(stepsPerRevolution, rotationalStepperPin1, rotationalStepperPin2, rotationalStepperPin3, rotatioanlStepperPin4); 
Stepper extrusionStepperMotor(stepsPerRevolution, extrusionStepperPin1, extrusionStepperPin2, extrusionStepperPin3, extrusionStepperPin4);

void setup(){
  pinMode(limitSwitchPin, INPUT); 
  pinMode(rotationalStepperPin1, INPUT);
  pinMode(rotationalStepperPin2, INPUT);
  pinMode(rotatioanlStepperPin3, INPUT); 
  pinMode(rotatioanlStepperPin4, INPUT); 
  pinMode(extrusionStepperPin1, INPUT); 
  pinMode(extrusionStepperPin2, INPUT); 
  pinMode(extrusionStepperPin3, INPUT); 
  pinMode(extrusionStepperPin4, INPUT); 
  pinMode(UV_RelayPin, INPUT); 
  pinMode(toggleOnButtonPin, INPUT); 
  pinMode(toggleEmergencyButtonPin, INPUT); 
}

void loop(){
  
}

boolean UV_timedRun(int milliseconds){
  do{
     digitalWrite(UV_RelayPin, HIGH); 
  }while(!waitMilliseconds(milliseconds);
  
  digitalWrite(UV_RelayPin, LOW); 
}

boolean waitMilliseconds(int milliseconds){
  unsigned long currentMilliseconds = millis();
  if(currentMilliseconds-previousMilliseconds >= milliseconds){
    previousMilliseconds = currentMilliseconds;
    return true;
  }else{
    return false; 
  }
}

void openContainer(){
  //Move stepper to extrude the table outside of the container for remote operation. 
  extrusionStepperMotor.step(mm_to_steps(mmToOpen));
}
void closeContainer(){
  //Move stepper to retract the table back into the container. 
  extrusionStepperMotor.step(mm_to_steps(mmToClose));
}

int mm_to_steps(double mm){
  //TODO: Convert mm to steps
}

int degrees_to_steps(double degree){
  //TODO: Convert degrees to steps 
}
