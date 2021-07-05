const byte ultrasoundtriggerPin = 2;
const byte ultrasoundechoPin = 4;
const byte infraredrightPin = 3;
const byte infraredleftPin = 5;
const byte rockerswitchinfraredPin = 6; // accepts only pin 2 and 3 for arduino uno
long lecture_echo; // long[2^31-1;2^31-1]
long obstacle_distance;
bool is_obstacle = false; // true if there is an obstacle
bool infrared_sensor_left_state; // HIGH or LOW
bool infrared_sensor_right_state; // HIGH or LOW
volatile bool activate_infrared_sensors = false;
int degree;

long distance_mesurement(){
  digitalWrite(ultrasoundtriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasoundtriggerPin, LOW);
  lecture_echo = pulseIn(ultrasoundechoPin,HIGH);
  obstacle_distance = lecture_echo /58;
  return obstacle_distance;
}

void line_follower(){
  infrared_sensor_right_state = digitalRead(infraredrightPin);
  infrared_sensor_left_state = digitalRead(infraredleftPin);
  if (infrared_sensor_right_state == LOW and infrared_sensor_left_state == LOW){
    forward();
  }
  else if (infrared_sensor_right_state == HIGH and infrared_sensor_left_state == LOW){
    turn_right(degree = 5);
  }
  else if (infrared_sensor_right_state == LOW and infrared_sensor_left_state == HIGH){
    turn_left(degree = 5);
  }
  else if (infrared_sensor_right_state == HIGH and infrared_sensor_left_state == HIGH){
    Serial.println("error");
  }
}
void turn_left(int degree){

}
void turn_right(int degree){
  
}
void forward(){
  
}
void backward(){
  
}

void Serialprint(long obstacle_distance){
  Serial.print("Distance en cm :");
  Serial.println(obstacle_distance);
  
}

void ISR_infrared(){
  if (activate_infrared_sensors == false){
    activate_infrared_sensors = true; 
  }
  else {
    activate_infrared_sensors = false;
  }
}

void setup(){
  pinMode(ultrasoundtriggerPin, OUTPUT);
  digitalWrite(ultrasoundtriggerPin, LOW);
  pinMode(ultrasoundechoPin, INPUT);
  pinMode(infraredleftPin, INPUT);
  pinMode(infraredrightPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(rockerswitchinfraredPin),ISR_infrared,RISING); // ISR for Interupt Service Routine
  Serial.begin(9600);

}

void loop(){
  obstacle_distance = distance_mesurement();
  Serialprint(obstacle_distance);
  if (activate_infrared_sensors == true){
    line_follower();
  }
}

