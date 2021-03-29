#include<Stepper>

unsigned long previousMilliseconds = 0; 

int limitSwitchLeft = 9;
int limitSwitchRight = 8;

//Each Stepper Motor takes 4 pins 
int UV_RelayPin = 13; 

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

boolean EMERGENCY_INTERRUPT_STATE = false;
boolean ON_STATE = false; 
boolean SANATIZE_STATE = false; 
boolean OFF_STATE = false; 
boolean isClosed = false; 

Stepper rotationalStepperMotor(stepsPerRevolution, rotationalStepperPin1, rotationalStepperPin2, rotationalStepperPin3, rotatioanlStepperPin4); 

void setup(){
  pinMode(LED_onPin, OUTPUT); 
  pinMode(LED_emergencyStopIndicator, OUTPUT); 
  pinMode(limitSwitchLeft, INPUT); 
  pinMode(limitSwitchRight, INPUT);
  pinMode(rotationalStepperPin1, INPUT);
  pinMode(rotationalStepperPin2, INPUT);
  pinMode(rotationalStepperPin3, INPUT); 
  pinMode(rotationalStepperPin4, INPUT); 
  pinMode(UV_RelayPin, OUTPUT); 
  pinMode(toggleOnButtonPin, INPUT); 
  //attachInterrupt(digitalPinToInterrupt(tactileEmergencyStopPin), emergencyInterrupt(), CHANGE); 
}

void loop(){
  if(digitalRead(limitSwitchLeft) == HIGH) and if(digitalRead(limitSwitchRight) == HIGH)
    if(digitalRead(toggleOnButtonPin) == HIGH)
      ON_STATE = true; 
    }    
    if(ON_STATE){
      onProcedure();
    }
    if(SANATIZE_STATE){
      sanatizeProcedure();
    }
    if(OFF_STATE){
      offProcedure();
    }
  }else{
    blinkEmergencyLED(); 
  }
}

void onProcedure(){
  if(!isClosed){
    closeContainer(); 
  }else{
    SANATIZE_STATE = true; 
  }
}

void offProcedure(){
  if(isClosed){
    openContainer();
  }
}

void sanatizeProcedure(){
  if(isClosed){
    UV_timedRun(UV_Runtime_1);
    setRotationalMotorDegrees(rotationInDegrees1);
    UV_timedRun(UV_Runtime_2);
    setRotationalMotorDegrees(rotationInDegrees2);
    UV_timedRun(UV_Runtime_3);
    setRotationalMotorDegrees(rotationInDegrees3);
    UV_timedRun(UV_Runtime_4);
    setRotationalMotorDegrees(rotationInDegrees4);
    SANATIZE_STATE = false; 
    ON_STATE = false; 
    OFF_STATE = true; 
  }
}

void UV_timedRun(int milliseconds){
  do{
     setRelay(true);
  }while(!waitMilliseconds(milliseconds);
  
    setRelay(false);
}

void emergencyInterrupt(){
  EMERGENCY_INTERRUPT_STATE = true; 
}

void blinkEmergencyLED(){
 digitalWrite(LED_emergencyStopIndicator, HIGH); 
 delay(100); 
 digitalWrite(LED_emergencyStopIndicator, HIGH); 
 delay(100); 
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

int mm_to_steps(double mm){
  //TODO: Convert mm to steps
}

int degrees_to_steps(double degree){
  //TODO: Convert degrees to steps 
}
