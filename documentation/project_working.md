# Project Working

The rover operates as a semi autonomous system designed for disaster rescue.

Step 1 Navigation

The rover moves forward while scanning surroundings using an ultrasonic sensor mounted on a servo motor.

If an obstacle is detected the rover changes direction.

Step 2 Pit Detection

Infrared sensors underneath detect pits or holes and prevent the rover from falling.

Step 3 Human Detection

Human presence is detected using

ESP32-CAM AI vision  
PIR motion sensor  
Sound detection  

Step 4 Temperature Verification

MLX90614 infrared sensor measures body temperature.

Step 5 Health Monitoring

MAX30100 measures heart rate and blood oxygen level.

Step 6 Environmental Monitoring

Gas sensor detects hazardous gases.

Flame sensor detects fire hazards.

Step 7 Alert System

When a human or hazard is detected

Buzzer activates  
LED flashes  
GPS sends location
