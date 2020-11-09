#include<Stepper>

unsigned long previousMilliseconds = 0; 

int limitSwitchPin = 6;
//Each Stepper Motor takes 4 pins 
int rotationalStepperPin1 = 7, rotationalStepperPin2 = 6, rotationalStepperPin3 = 5, rotatioanlStepperPin4 = 4; 
int extrusionStepperPin1 = 3, extrusionStepperPin2 = 2, extrusionStepperPin3 = 1, extrusionStepperPin4 = 0; 
int UV_RelayPin = 12; 
int tactileOnButtonPin = 11; 
int tactileEmergencyStopPin = 10;

const int stepsPerRevolution = 200; //Depends on stepper motor 
const int mmToOpen = 0; //TBD 
const int mmToClose = 0; //TBD

const int UV_Runtime_1 = 0; //TBD
const int UV_Runtime_2 = 0; //TBD
const int UV_Runtime_3 = 0; //TBD
const int UV_Runtime_4 = 0; //TBD 

const int rotationInDegrees1 = 0; //TBD
const int rotationInDegrees2 = 0; //TBD 
const int rotationInDegrees3 = 0; //TBD 
const int rotationInDegrees4 = 0; //TBD  


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

void sanatizeProcedure(){
  if(!isTriggeredEmergencyButton){
    UV_timedRun(UV_Runtime_1);
    setRotationalMotorDegrees(rotationInDegrees1);
    UV_timedRun(UV_Runtime_2);
    setRotationalMotorDegrees(rotationInDegrees2);
    UV_timedRun(UV_Runtime_3);
    setRotationalMotorDegrees(rotationInDegrees3);
    UV_timedRun(UV_Runtime_4);
    setRotationalMotorDegrees(rotationInDegrees4);
  }
}

void openContainer(){
  //Move stepper to extrude the table outside of the container for remote operation. 
  setExtrusionMotorMM(mmToOpen);
}
void closeContainer(){
  //Move stepper to retract the table back into the container. 
  setExtrusionMotorMM(mmToClose);
}

void UV_timedRun(int milliseconds){
  do{
     setRelay(true);
  }while(!waitMilliseconds(milliseconds);
  
    setRelay(false);
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

void setRelay(boolean toggle){
  if(toggle){
    digitalWrite(UV_RelayPin, HIGH);
  }else{
    digitalWrite(UV_RelayPin, LOW); 
  }
}

void setExtrusionMotorMM(int mm){
   extrusionStepperMotor.step(mm_to_steps(mm));
}

void setExtrusionMotorStep(int steps){
  extrusionStepperMotor.step(steps);
}

void setRotationalMotorDegrees(int degree){
  rotationalStepperMotor.step(degrees_to_steps(degree));
}

void setRotationalMotorStep(int setps){
  rotationalStepperMotor.step(steps);
}

boolean isLimitSwitch(){
  if(digitalRead(limitSwitchPin) == HIGH)){
    return true; 
  }else{
    return false; 
  }
}

boolean isTriggeredOnButton(){
  if(digitalRead(tactileOnButtonPin) == HIGH){
    return true; 
  }else{
    return false; 
  }
}

boolean isTriggeredEmergencyButton(){
  if(digitalRead(tactileEmergencyStopPin) == HIGH){
    return true; 
  }else{
    return false; 
  }
}

int mm_to_steps(double mm){
  //TODO: Convert mm to steps
}

int degrees_to_steps(double degree){
  //TODO: Convert degrees to steps 
}
