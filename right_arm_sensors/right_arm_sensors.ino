/*
  right_arm_sensors

  Recieves values from an FSR and a Flex sensor for the right arm and publishes to its respective ROS topics.

  The circuit:
  - used FSR & Flex sensor schematics from Control & Power Team

  Notes:
  - Still need to add IMU.

  created 2021
  by Sohaib Khadri
  modified 16 Oct 2021
  by Sohaib Khadri

*/

#include <ros.h>
#include <std_msgs/Int16.h>

ros::NodeHandle  nh;

const int flexPin = A0;
const int fsrPin = A1; 

std_msgs::Int16 flexValue;
std_msgs::Int16 fsrValue;
ros::Publisher pub_right_flex("right_flex_value", &flexValue);
ros::Publisher pub_right_fsr("right_fsr_value", &fsrValue);

void setup() 
{ 
  nh.initNode();
  nh.advertise(pub_right_flex);
  nh.advertise(pub_right_fsr);
  
  //Serial.begin(9600); //Serial breaks ROS sync due to memory buffer overflow
  pinMode(flexPin,INPUT);
  pinMode(fsrPin,INPUT);
} 

void loop() 
{ 
  flexValue.data = analogRead(flexPin);
  fsrValue.data = analogRead(fsrPin);
  
  //Serial.print("Flex Value: ");
  //Serial.println(flexValue.data);
  //Serial.print("FSR Value: ");
  //Serial.println(fsrValue.data);

  pub_right_flex.publish(&flexValue);
  pub_right_fsr.publish(&fsrValue);
  nh.spinOnce();
  
  delay(20);
} 
