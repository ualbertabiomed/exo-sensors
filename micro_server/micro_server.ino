/*
  arduino_microserver

  Subscribes to "turn_servo" topic and turns the connected servo to an angle 0-180.
  Used to test and model ROS subcriber functionality. (O-Drive substitute)

  The circuit:
  - Single 9g microservo SG90 connected to the arduino

  Notes:
  - 

  created 2021
  by Sohaib Khadri
  modified 16 Oct 2021
  by Sohaib Khadri

*/

#include <Servo.h>
#include <ros.h>
#include <std_msgs/Int16.h>

ros::NodeHandle  nh;

Servo servo;
const int servoPin = 8;

void turnServo( const std_msgs::Int16 &servo_msg){
    servo.write(servo_msg.data); //set servo angle, should be from 0-180  
}

ros::Subscriber<std_msgs::Int16> servoSub("turn_servo", &turnServo);

void setup() {
  servo.attach(servoPin);
  nh.initNode();
  nh.subscribe(servoSub);
}

void loop() {
  nh.spinOnce();
  delay(20);
}
