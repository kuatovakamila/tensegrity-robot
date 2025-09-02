// Define L298N connections

// #import <Arduino.h>


//2
const int IN1 = 3;
const int IN2 = 4;
const int ENA = 2;
//3
const int driver3_IN1 = 9;
const int driver3_IN2 = 8;
const int driver3_ENA = 10;
//1
const int driver2_IN1 = 12;
const int driver2_IN2 = 11;
// const int driver2 driver3_IN1 = ;
// const int driver2 driver3_IN2 = ;
const int driver2_ENA = 13;
// const int driver3_IN1 = 
// const int driver2_driver3_ENA = ;
// const int potentiometerPin = A0;
const int potentiometerPin = A1;
const int potPin2 = A0;
const int potPin3 = A2;
const float maxDistance = 73.8;   // Maximum distance in mm
const float minDistance = 0;
const float tolerance = 1;

// возможные стейты (поднять/опустить)
enum State {LIFT, RETRACT};

// void setupDriver(Driver driver){

// }

State state1;
State state2; 
State state3;
State state4;

void setup() {
  // Set all the motor control pins to outputs
  Serial.begin(9600);                  // Initialize serial communication at 9600 bits per second
  
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);
//   pinMode(ENA, OUTPUT);
    pinMode(driver3_IN1, OUTPUT);
    pinMode(driver3_IN2, OUTPUT);
    pinMode(driver3_ENA, OUTPUT);
  
  int sensorValue1 = analogRead(potentiometerPin);  
  float distance1 = map(sensorValue1, 0, 1023, 0, 7380) / 100.0; 
  int sensorValue2 = analogRead(potPin2);  
  float distance2 = map(sensorValue2, 0, 1023, 0, 7380) / 100.0; 
    int sensorValue3 = analogRead(potPin3);
    float distance3 = map(sensorValue3, 0, 1023, 0, 7380) / 100.0;
  if(distance1 >= tolerance){
    state1 = LIFT;
  }else{
    state1 = RETRACT;
  }
  if(distance2 >=  tolerance){
    state2 = LIFT;
  }else{
    state2 = RETRACT;
  }
    if(distance3 >= tolerance){
        state3 = LIFT;
    }else{
        state3 = RETRACT;
    }
}

void loop() {
  // Read the potentiometer value and calculate distance
  int sensorValue1 = analogRead(potentiometerPin);  
  float distance1 = map(sensorValue1, 0, 1023, 0, 7380) / 100.0; 
  int sensorValue2 = analogRead(potPin2);  
  float distance2 = map(sensorValue2, 0, 1023, 0, 7380) / 100.0; 
  int sensorValue3 = analogRead(potPin3);  
  float distance3 = map(sensorValue3, 0, 1023, 0, 7380) / 100.0; 
  // Print sensor value and distance to serial monitor
  Serial.print("Sensor1 Value: ");
  Serial.print(sensorValue1);
  Serial.print(" -> Distance: ");
  Serial.print(distance1);
  Serial.print(" mm. ");
  Serial.print("Sensor2 Value: ");
  Serial.print(sensorValue2);
  Serial.print(" -> Distance: ");
  Serial.print(distance2);
  Serial.print(" mm");
    Serial.print("Sensor3 Value: ");
    Serial.print(sensorValue3);
    Serial.print(" -> Distance: ");
    Serial.print(distance3);
    Serial.println(" mm");
  // чекаем на верхний и нижний лимиты (толеранс тут просто как мера против рандомных неточностей)
  bool upLimReached1 = (abs(maxDistance - distance1) <= tolerance);
  bool lowLimReached1 = (abs(distance1 - minDistance) <= tolerance);
  bool upLimReached2 = (abs(maxDistance - distance2) <= tolerance);
  bool lowLimReached2 = (abs(distance2 - minDistance) <= tolerance);
    bool upLimReached3 = (abs(maxDistance - distance3) <= tolerance);
    bool lowLimReached3 = (abs(distance3 - minDistance) <= tolerance);
  // на каждой итерации чекаем стейт
  switch(state1){
    case LIFT:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        analogWrite(ENA, 255);
        // если достигнут верхний лимит, переводим стейт на опускание
        if(upLimReached1){
            state1 = RETRACT;
        }
        break;
    case RETRACT:
        digitalWrite(IN2, LOW);
        digitalWrite(IN1, HIGH);
        // наоборот
        if(lowLimReached1){
          state1 = LIFT;
        }
        break;        
  }

  switch(state2){
    case LIFT:
        digitalWrite(driver3_IN1, LOW);
        digitalWrite(driver3_IN2, HIGH);
        analogWrite(driver3_ENA, 255);
        // если достигнут верхний лимит, переводим стейт на опускание
        if(upLimReached2){
            state2 = RETRACT;
        }
        break;
    case RETRACT:
        digitalWrite(driver3_IN2, LOW);
        digitalWrite(driver3_IN1, HIGH);
        // наоборот
        if(lowLimReached2){
          state2 = LIFT;
        }
        break;        
  }

    switch(state3){
        case LIFT:
            digitalWrite(driver2_IN1, LOW);
            digitalWrite(driver2_IN2, HIGH);
            analogWrite(driver2_ENA, 255);
            // если достигнут верхний лимит, переводим стейт на опускание
            if(upLimReached3){
                state3 = RETRACT;
            }
            break;
        case RETRACT:
            digitalWrite(driver2_IN2, LOW);
            digitalWrite(driver2_IN1, HIGH);
            // наоборот
            if(lowLimReached3){
                state3 = LIFT;
            }
            break;
    }

}