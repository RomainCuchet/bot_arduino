const byte ultrasound_sensor_trigger_pin = 2;
const byte ultrasound_sensor_echo_pin = 4;
const byte infrared_sensor_right_pin = ;
const byte infrared_sensor_left_pin = ;
long lecture_echo; // long[2^31-1;2^31-1]
long obstacle_distance;
bool is_obstacle = false; // true if there is an obstacle
bool infrared_sensor_left_state; // HIGH or LOW
bool infrared_sensor_right_state; // HIGH or LOW

long distance_mesurement(){
  digitalWrite(ultrasound_sensor_trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasound_sensor_trigger_pin, LOW);
  lecture_echo = pulseIn(ultrasound_sensor_echo_pin,HIGH);
  obstacle_distance = lecture_echo /58;
  return obstacle_distance;
}

void line_follower(){
  infrared_sensor_right_state = digitalRead(infrared_sensor_right_pin)
  infrared_sensor_left_state = digitalRead(infrared_sensor_left_pin)
  if (infrared_sensor_right_state == LOW and infrared_sensor_left_state == LOW){
    forward()
  }
  else if (infrared_sensor_right_state == HIGH and infrared_sensor_left_state == LOW){
    turn_right(degree = 5)
  }
  else if (infrared_sensor_right_state == LOW and infrared_sensor_left_state == HIGH){
    turn_left(degree = 5)
  }
  else if (infrared_sensor_right_state == HIGH and infrared_sensor_left_state == HIGH){
    turn_(degree = 90)// à déterminer
  }
}
void turn_left(degree){

}
void turn_right(degree){
  
}
void forward(){
  
}
void backward(){
  
}

void Serialprint(long obstacle_distance){
  Serial.print("Distance en cm :");
  Serial.println(obstacle_distance);
  
}

void setup(){
  pinMode(ultrasound_sensor_trigger_pin, OUTPUT);
  digitalWrite(ultrasound_sensor_trigger_pin, LOW);
  pinMode(ultrasound_sensor_echo_pin, INPUT);
  pinMode(infrared_sensor_left_pin, INPUT)
  pinMode(infrared_sensor_right_pin, INPUT)
  Serial.begin(9600);

}

void loop(){
  obstacle_distance = distance_mesurement();
  Serialprint(obstacle_distance);
  delay(1500);
}
