/*
  arm_sensors

  Recieves values from an FSR and a Flex sensor and outputs it to serial output.

  The circuit:
  - used FSR & Flex sensor schematics from Control & Power Team

  Notes:
  - Still need to add IMU.

  created 2021
  by Sohaib Khadri
  modified 16 Oct 2021
  by Sohaib Khadri

*/

const int flexPin = A0;
const int fsrPin = A1; 


int flexValue;
int fsrValue;

void setup() 
{ 
  Serial.begin(9600);
  pinMode(flexPin,INPUT);
  pinMode(fsrPin,INPUT);
} 

void loop() 
{ 
  
  flexValue = analogRead(flexPin);
  fsrValue = analogRead(fsrPin);
  Serial.print("Flex Value: ");
  Serial.println(flexValue);
  Serial.print("FSR Value: ");
  Serial.println(fsrValue);
  
  delay(100);
} 
