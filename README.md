# exo-sensors
Arduino code for reading sensor data from UABiomed's ALEX

## left-arm-sensors
Recieves values from an FSR and a Flex sensor for the left arm and publishes to its respective ROS topics. Publishes to "left_flex_value" & "left_fsr_value".


## right-arm-sensors
Recieves values from an FSR and a Flex sensor for the right arm and publishes to its respective ROS topics. Publishes to "right_flex_value" & "right_fsr_value".

## micro_servo
Subscribes to "turn_servo" topic and turns the connected servo to an angle 0-180.Used to test and model ROS subcriber functionality as an O-Drive substitute.
