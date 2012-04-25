#include <Servo.h> 

const int photo = A0;
int light_a;
int light;

const int servo_pins[] = {11, 6};
const int NUM_SERVOS = 2;
Servo servos[2];
int pos;
 
void setup() 
{ 
  pinMode(photo, INPUT);
  for(int i = 0;i<NUM_SERVOS;i++){
    Servo s;
    s.attach(servo_pins[i]);
    servos[i] = s;
  }
  
  Serial.begin(9600);
  
  light_a = analogRead(photo);
} 
 
void loop() 
{ 
  int temp_light = analogRead(photo);
  if( abs(temp_light - light_a) > 5){
    light_a = temp_light;
    light = map(light_a, 350, 800, 10, 170);
    if(light > 170){ light = 170; }
    if(light < 10){ light = 10; }
    move(light); 
  }
}

void move(int target){
  if( target > pos){
    for(int t = pos; t < target ; t++){
      for(int s = 0; s < NUM_SERVOS ; s++){
        servos[s].write(t);              // tell servo to go to position in variable 'pos' 
      }
      pos = t;
      delay(15);
      //Serial.println(String(light_a) );
    } 
  } else {
    for(int t = pos; t > target ; t--){
      for(int s = 0; s < NUM_SERVOS ; s++){
        servos[s].write(t);              // tell servo to go to position in variable 'pos' 
      }
      pos = t;
      delay(15);
       // Serial.println(String(light_a) );
    } 
  }
}
