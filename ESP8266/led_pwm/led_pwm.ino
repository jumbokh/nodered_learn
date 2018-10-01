/*
 * Copyright (c) 2015, circuits4you.com
 * All rights reserved.
/* Generates PWM on Internal LED Pin GPIO 2 of ESP8266*/

#include <ESP8266WiFi.h>
#define LED 4

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

//=======================================================================
//                    Power on setup
//=======================================================================
void setup() {
  Serial.begin(115200);
  pinMode(LED,OUTPUT);
}

//=======================================================================
//                    Main Program Loop
//=======================================================================
void loop() {
  //PWM Value varries from 0 to 1023  
  Serial.println("10 % PWM");
  analogWrite(LED,102);
  delay(2000);

  Serial.println("20 % PWM");
  analogWrite(LED,205);
  delay(2000);

  Serial.println("40 % PWM");
  analogWrite(LED,410);
  delay(2000);

  Serial.println("70 % PWM");
  analogWrite(LED,714);
  delay(2000);

  Serial.println("100 % PWM");
  analogWrite(LED,1024);
  delay(2000);

  //Continuous Fading
  Serial.println("Fadding Started");
  while(1)
  {
    // set the brightness of pin 9:
    analogWrite(LED, brightness);
  
    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;
  
    // reverse the direction of the fading at the ends of the fade:
    if (brightness <= 0 || brightness >= 1023) {
      fadeAmount = -fadeAmount;
    }
    // wait for 30 milliseconds to see the dimming effect
    delay(10);
  }
}
//=======================================================================