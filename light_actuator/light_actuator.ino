#include <Servo.h> 

const int photo = A0;
int light;

const int servo_pins[] = {11, 6};
const int NUM_SERVOS = 2;
Servo servos[2];
 
void setup() 
{ 
  pinMode(photo, INPUT);
  for(int i = 0;i<NUM_SERVOS;i++){
    Servo s;
    s.attach(servo_pins[i]);
    servos[i] = s;
  }
  
  Serial.begin(9600);
} 
 
void loop() 
{ 
  light = analogRead(photo);
  Serial.println(light);
  for(int pos = 0; pos < 90; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    move(pos);
  } 
  
  for(int pos = 170; pos>=10; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    move(pos);
  } 
}

void move(int pos){
  for(int s = 0; s < NUM_SERVOS ; s++){
    servos[s].write(pos);              // tell servo to go to position in variable 'pos' 
  }
  
  delay(15);
}
