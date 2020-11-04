int limitSwitchPin = 6;
//Each Stepper Motor takes 4 pins 
int rotationalStepperPin1 = 7, rotationalStepperPin2 = 6, rotationalStepperPin3 = 5, rotatioanlStepperPin4 = 4; 
int extrusionStepperPin1 = 3, extrusionStepperPin2 = 2, extrusionStepperPin3 = 1, extrusionStepperPin4 = 0; 
int UV_RelayPin = 12; 
int toggleOnButtonPin = 11; 
int toggleEmergencyStopPin = 10;

const int stepsPerRevolution = 200; //Depends on stepper motor 

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

void move_x_and_rotate(double degree, double mm){
    Stepper_x.step(mm_to_steps(mm)); 
    delay(10); // We can't delay! 
    digitalWrite(solenoidPin, HIGH); 
    Stepper_rotation.step(degrees_to_steps(degree));

    delay(10); // We can't delay!
}

void openContainer(){
  //Move stepper to extrude the table outside of the container for remote operation. 
  Stepper_x.step(mm_to_steps(mm));
}
void closeContainer(){
  //Move stepper to extrude the table outside of the container for remote operation. 
  Stepper_x.step(mm_to_steps(-mm));
}

int mm_to_steps(double mm){
  //TODO: Convert mm to steps
}

int degrees_to_steps(double degree){
  //TODO: Convert degrees to steps 
}
