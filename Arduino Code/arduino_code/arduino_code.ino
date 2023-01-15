#include <HCSR04.h> // import the ultrasonic sensor library

UltraSonicDistanceSensor Sensor(13, 12);  // Initialize sensor that uses digital pins 13 and 12.

int BuzzerPin = 11; //buzzer pin go to pin 11
int Distance; // variable to store the value of the sensor
int MinDistance = 100; // Set the min distance in centimeters.

void setup () { 
  Serial.begin(9600); 
    pinMode(BuzzerPin,OUTPUT); // set the Buzzer Pin as Output.
}

void loop () {
    // Every 50 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    Distance = Sensor.measureDistanceCm(); // read the distance from the Ultrasonic sensor.
    Serial.println(Distance);
    delay(50); // wait for 50 ms

    if (Distance < MinDistance) // check if the distance is less then the min distance.
      {
         digitalWrite(BuzzerPin,HIGH); // turn on the buzzer.
      }
      else
      {
         digitalWrite(BuzzerPin,LOW); //turn off the buzzer.
      }
}
