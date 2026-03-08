# Project Working

The rover is designed to operate in disaster environments to locate survivors and detect hazards.

## Navigation

The rover moves forward and scans the environment using an ultrasonic sensor mounted on a servo motor.

If an obstacle is detected, the rover selects a new direction.

## Pit Detection

IR sensors mounted underneath detect pits or holes and prevent the rover from falling.

## Human Detection

Human presence is detected using:

• ESP32-CAM AI vision  
• PIR motion sensor  
• Sound detection  

## Temperature Verification

The MLX90614 infrared temperature sensor measures body temperature to confirm human presence.

## Health Monitoring

The MAX30100 sensor measures heart rate and oxygen level of detected victims.

## Environmental Monitoring

Gas sensors detect hazardous gases.

Flame sensors detect fire hazards.

## Alert System

If a human or hazard is detected:

• Buzzer activates  
• LED alert flashes  
• Data is transmitted to the monitoring system
