int inputPin = 13;

void setup() {
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(inputPin)==HIGH){
    Serial.println("Circuit High");
  }else{
    Serial.println("Circuit Low");
  }

  delay(100);
}
