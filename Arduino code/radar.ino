//Upload this to the arduino and run the python progam radar.py
//Remember to close this page while running the python program because serial port can only connect to one program at a time

#include <Servo.h>

#define CLK 3;
#define DIO 4;

const int servo1Pin = 6;
const int trigPin = 9;
const int echoPin = 8;

float distance, duration;
int angle;
float serial_distance;

Servo servo1;


void setup() {
  // put your setup code here, to run once:
  servo1.attach(servo1Pin);
  servo1.write(90);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  for (angle; angle<=180; angle++){
    serial_distance = measure_distance();
    servo1.write(angle);

    Serial.print(serial_distance);
    Serial.print(",");
    Serial.println(angle);
    delay(100);
  }

  for (angle; angle>=0; angle--){
    serial_distance = measure_distance();
    servo1.write(angle);

    Serial.print(serial_distance);
    Serial.print(",");
    Serial.println(angle);
    delay(100);
  }

}

int measure_distance(){
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 

  duration = pulseIn(echoPin, HIGH);
  distance = duration * .0349 / 2;

  return(distance);
}


