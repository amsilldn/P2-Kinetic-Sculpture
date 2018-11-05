#include <Stepper.h>

//number of steps the motor will take with one call
const int num_steps = 200;
                            
// initialize the stepper library on pins 4-7 n 8-11
Stepper myStepper1(num_steps,4,5,6,7);
Stepper myStepper2(num_steps,8,9,10,11);      

//distance sensor one
const int trigPin1 = 2;
const int echoPin1 = 3;

//distance snesor 2
const int trigPin2 = 1;
const int echoPin2 = 12;

//stores the distance captured by each sensor
//sensor 1
float distance1, duration1, distance2, duration2;

void setup() {
  myStepper1.setSpeed(60); //left
  myStepper2.setSpeed(60); //right

  //sensor 1 - trig is output & echo is input
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  //sensor 2 - trig is output & echo is input
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
  Serial.begin(9600); //begin serial communication

}

void loop() {
  
  //clear trig pin 1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);

  //set trig pin 1 to high for 20 microseconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin1, LOW);

  //read the echo pin 1, return sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);

  //calculate distance
  //Math for finding distance comes from 
  //https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
  distance1 = (duration1*0.0343)/2;

  //print distance to serial monitor
  Serial.print("Distance 1: ");
  Serial.println(distance1);

  //if distance sensor 1 returns any distance under 1 meter
  //have the gears go through their full rotation
  //didn't feel like doing the math to have it rotate to a certain degree/angle
  //fuck math
  if (1.00 < distance1 && distance1 < 100.00) {
    //open gear one to reveal first image
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    delay(5000);
    //close gear two and open gear one to reveal second image
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    delay(5000);
    //close gear two and open gear one to reveal third image
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    delay(5000);
    //close gear two and open gear one to reveal fourth image
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    delay(5000); 
    //close gear two to reset
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    delay(500);
  }

  //clear trig pin 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);

  //set trig pin 2 to high for 20 microseconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin2, LOW);

  //read the echo pin 2, return sound wave travel time in microseconds
  duration2 = pulseIn(echoPin2, HIGH);

  //calculate distance
  //Math for finding distance comes from 
  //https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
  distance2 = (duration2*0.0343)/2;

  //print distance to serial monitor
  Serial.print("Distance 2: ");
  Serial.println(distance2);

  //if distance sensor 1 returns any distance under 1 meter
  //have the gears go through their full rotation
  //didn't feel like doing the math to have it rotate to a certain degree/angle
  //fuck math
  if (1.00 < distance2 && distance2 < 100.00) {
    //open gear one to reveal first image
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    delay(5000);
    //close gear two and open gear one to reveal second image
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    delay(5000);
    //close gear two and open gear one to reveal third image
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    delay(5000);
    //close gear two and open gear one to reveal fourth image
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    myStepper1.step(num_steps);
    delay(5000); 
    //close gear two to reset
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    myStepper2.step(num_steps);
    delay(500);
  }
  
  delay(500);
}
