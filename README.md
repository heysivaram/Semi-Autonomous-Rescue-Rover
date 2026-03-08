# Semi-Autonomous Rescue Rover

![Rescue Rover Prototype](images/rover_prototype.jpg)

## IEEE Research Publication

This project has been presented in an IEEE conference.

| Document | Link |
|--------|------|
| 📄 IEEE Paper | [Download Paper](publications/IEEE_Rescue_Rover_Paper.pdf) |
| 🏆 IEEE Conference Certificate | [View Certificate](publications/IEEE_Conference_Certificate.pdf) |

---

# Project Overview

The ** Semi-Autonomous Rescue Rover** is designed to assist rescue teams in disaster environments such as earthquakes, collapsed buildings, and hazardous zones.

The rover integrates **robotics, artificial intelligence, environmental monitoring, and health sensing** to detect survivors and hazards.

The system uses an **ESP32 microcontroller** for navigation and sensor integration, while an **ESP32-CAM module performs AI-based human detection**.

---

# AI Human Detection

The ESP32-CAM performs **real-time human detection** using a lightweight deep learning model deployed on the camera module.

![AI Detection](images/ai_human_detection.jpg)

---

# System Architecture

The system consists of two main processing units.

• ESP32 Main Controller  
• ESP32-CAM Vision Module  

ESP32 Responsibilities

• Sensor integration  
• Motor control  
• Navigation  
• Hazard detection  

ESP32-CAM Responsibilities

• Image capture  
• AI human detection  
• Visual monitoring  

---

# Key Features

• AI human detection using ESP32-CAM  
• Infrared temperature sensing using MLX90614  
• Heart rate and SpO₂ monitoring using MAX30100  
• Obstacle avoidance using ultrasonic sensor  
• Pit detection using infrared sensors  
• Gas and flame hazard detection  
• Sound detection for survivor voice  
• GPS location tracking  
• Semi-autonomous navigation  
• Environmental monitoring  

---

# Components Used

| Component | Purpose |
|----------|--------|
| ESP32 | Main microcontroller |
| ESP32-CAM | AI vision detection |
| Ultrasonic Sensor HC-SR04 | Obstacle detection |
| Servo Motor | Ultrasonic scanning |
| PIR Sensor | Human motion detection |
| MLX90614 Infrared Sensor | Human body temperature |
| MAX30100 Pulse Oximeter | Heart rate and SpO₂ |
| Sound Sensor | Detect survivor voice |
| Gas Sensor MQ-2 | Gas detection |
| Flame Sensor | Fire detection |
| LDR Module | Automatic lighting |
| IR Sensors (4) | Pit detection |
| GPS Module NEO-6M | Location tracking |
| L298N Motor Driver | Motor control |
| DC Motors | Rover movement |
| Buzzer | Alert system |
| LEDs | Visual alerts |
| Battery Pack | Power supply |
| Rover Chassis | Robot structure |

---

# Hardware Connections

### Ultrasonic Sensor
Trigger → GPIO5  
Echo → GPIO18  

### Servo Motor
GPIO25  

### PIR Sensor
GPIO19  

### Sound Sensor
GPIO33  

### Gas Sensor
GPIO34  

### Flame Sensor
GPIO35  

### LDR Module
GPIO32  

### MLX90614
SDA → GPIO21  
SCL → GPIO22  

### MAX30100
SDA → GPIO21  
SCL → GPIO22  

### GPS Module
RX → GPIO16  
TX → GPIO17  

### Buzzer
GPIO4  

### Alert LED
GPIO2  

### IR Pit Sensors
IR1 → GPIO13  
IR2 → GPIO15  
IR3 → GPIO16  
IR4 → GPIO17  

### Motor Driver
IN1 → GPIO12  
IN2 → GPIO14  
IN3 → GPIO27  
IN4 → GPIO26  

---

# Project Working

The rescue rover operates as a **semi-autonomous search and rescue robot**.

### 1 Navigation

The rover moves forward while scanning the environment using an **ultrasonic sensor mounted on a servo motor**.

If an obstacle is detected, the rover automatically changes direction.

### 2 Pit Detection

Infrared sensors placed underneath detect pits or holes and prevent the rover from falling.

### 3 Human Detection

Human presence is detected using:

• ESP32-CAM AI vision  
• PIR motion sensor  
• Sound detection  

### 4 Temperature Verification

The MLX90614 infrared sensor measures body temperature to confirm human presence.

### 5 Health Monitoring

The MAX30100 sensor measures:

• Heart rate  
• Blood oxygen level  

### 6 Environmental Monitoring

Gas sensor detects hazardous gases.

Flame sensor detects fire hazards.

### 7 Alert System

When a survivor or hazard is detected:

• Buzzer activates  
• LED alert flashes  
• GPS location is transmitted  

---

# Applications

• Disaster rescue missions  
• Military reconnaissance  
• Hazardous environment monitoring  
• Industrial safety inspection  

---

# THANK YOU


