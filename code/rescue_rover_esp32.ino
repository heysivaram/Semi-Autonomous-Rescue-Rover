#include <Wire.h>
#include <Servo.h>
#include <Adafruit_MLX90614.h>
#include "MAX30100_PulseOximeter.h"
#include <TinyGPS++.h>

#define TRIG 5
#define ECHO 18

#define PIR 19
#define SOUND 33
#define GAS 34
#define FLAME 35

#define LDR 32

#define BUZZER 4
#define ALERT_LED 2
#define HEADLIGHT 23

#define IR1 13
#define IR2 15
#define IR3 16
#define IR4 17

#define IN1 12
#define IN2 14
#define IN3 27
#define IN4 26

#define GPS_RX 16
#define GPS_TX 17

Servo scanner;

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
PulseOximeter pox;
TinyGPSPlus gps;

long duration;
int distance;

void setup()
{
Serial.begin(115200);

Wire.begin();

mlx.begin();
pox.begin();

pinMode(TRIG,OUTPUT);
pinMode(ECHO,INPUT);

pinMode(PIR,INPUT);
pinMode(SOUND,INPUT);
pinMode(GAS,INPUT);
pinMode(FLAME,INPUT);

pinMode(LDR,INPUT);

pinMode(IR1,INPUT);
pinMode(IR2,INPUT);
pinMode(IR3,INPUT);
pinMode(IR4,INPUT);

pinMode(BUZZER,OUTPUT);
pinMode(ALERT_LED,OUTPUT);
pinMode(HEADLIGHT,OUTPUT);

pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);

scanner.attach(25);
scanner.write(90);

Serial.println("Rescue Rover Initialized");
}

void loop()
{

checkObstacle();

checkPit();

detectHuman();

checkTemperature();

checkHealth();

checkGas();

checkFlame();

checkSound();

checkLight();

readGPS();

moveForward();

delay(300);
}

void moveForward()
{
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
}

void stopMotors()
{
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
}

void turnLeft()
{
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
}

void turnRight()
{
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
}

void checkObstacle()
{

digitalWrite(TRIG,LOW);
delayMicroseconds(2);

digitalWrite(TRIG,HIGH);
delayMicroseconds(10);

digitalWrite(TRIG,LOW);

duration=pulseIn(ECHO,HIGH);

distance=duration*0.034/2;

Serial.print("Distance: ");
Serial.println(distance);

if(distance<25)
{

stopMotors();

scanner.write(40);
delay(400);

int leftDist=measureDistance();

scanner.write(140);
delay(400);

int rightDist=measureDistance();

scanner.write(90);

if(leftDist>rightDist)
{
turnLeft();
delay(700);
}

else
{
turnRight();
delay(700);
}

}

}

int measureDistance()
{

digitalWrite(TRIG,LOW);
delayMicroseconds(2);

digitalWrite(TRIG,HIGH);
delayMicroseconds(10);

digitalWrite(TRIG,LOW);

duration=pulseIn(ECHO,HIGH);

return duration*0.034/2;

}

void checkPit()
{

if(digitalRead(IR1)==LOW ||
digitalRead(IR2)==LOW ||
digitalRead(IR3)==LOW ||
digitalRead(IR4)==LOW)
{

Serial.println("Pit Detected");

stopMotors();

digitalWrite(BUZZER,HIGH);
delay(500);

moveForward();
delay(1000);

}

}

void detectHuman()
{

if(digitalRead(PIR)==HIGH)
{

Serial.println("Human Motion Detected");

digitalWrite(ALERT_LED,HIGH);
digitalWrite(BUZZER,HIGH);

delay(500);

digitalWrite(BUZZER,LOW);

}

}

void checkTemperature()
{

double temp = mlx.readObjectTempC();

Serial.print("Body Temp: ");
Serial.println(temp);

if(temp>34 && temp<40)
{

Serial.println("Possible Human Body Detected");

digitalWrite(ALERT_LED,HIGH);

}

}

void checkHealth()
{

pox.update();

Serial.print("Heart Rate: ");
Serial.println(pox.getHeartRate());

Serial.print("SpO2: ");
Serial.println(pox.getSpO2());

}

void checkGas()
{

int gasVal = analogRead(GAS);

Serial.print("Gas: ");
Serial.println(gasVal);

if(gasVal>3000)
{

Serial.println("Gas Hazard");

digitalWrite(BUZZER,HIGH);

}

}

void checkFlame()
{

if(digitalRead(FLAME)==LOW)
{

Serial.println("Flame Detected");

digitalWrite(BUZZER,HIGH);

}

}

void checkSound()
{

int sound = analogRead(SOUND);

if(sound>2000)
{

Serial.println("Sound Detected");

digitalWrite(ALERT_LED,HIGH);

}

}

void checkLight()
{

int light = analogRead(LDR);

if(light<1500)
{
digitalWrite(HEADLIGHT,HIGH);
}

else
{
digitalWrite(HEADLIGHT,LOW);
}

}

void readGPS()
{

while(Serial.available()>0)
{

gps.encode(Serial.read());

}

if(gps.location.isUpdated())
{

Serial.print("Latitude: ");
Serial.println(gps.location.lat());

Serial.print("Longitude: ");
Serial.println(gps.location.lng());

}

}
