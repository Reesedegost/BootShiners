
int solenoidPin; 
int UV_pin; 
int led_ACTIVE, led_INACTIVE;
int limitSwitch_pin; 
Stepper Stepper_x; 
Stepper Stepper_rotation; 


void setup() {
  pinmode(limitSwitch_pin, INPUT);
  pinmode(UV_pin, OUTPUT); 
  pinmode(led_ACTIVE, OUTPUT); 
  pinmode(led_INACTIVE, OUTPUT); 
}

void loop() {
  if(limitSwitch_pin == HIGH){
    digitalWrite(led_INACTIVE, LOW); 
    digitalWrite(led_ACTIVE, HIGH);
    closeContainer(); 
    digitalWrite(UV_pin, HIGH); 
    move_x_and_rotate(//degree and mm); 
    move_x_and_rotate(//degree and mm); 
    digitalWrite(UV_pin, LOW); 
  }else{
    digitalWrite(led_ACTIVE, LOW); 
    digitalWrite(led_INACTIVE, HIGH); 
    openContainer();
  }
}

void move_x_and_rotate(double degree, double mm){
    Stepper_x.step(mm_to_steps(mm)); 
    delay(10);
    digitalWrite(solenoidPin, HIGH); 
    Stepper_rotation.step(degrees_to_steps(degree));

    delay(10);
}

void openContainer(){
  //Move stepper to extrude the table outside of the container for remote operation. 
  Stepper_x.step(mm_to_steps(mm));
}
void closeContainer(){
  //Move stepper to extrude the table outside of the container for remote operation. 
  Stepper_x.step(mm_to_steps(-mm));
}

double mm_to_steps(double mm){
  //TODO: Convert mm to steps
}

double degrees_to_steps(double degree){
  //TODO: Convert degrees to steps 
}
