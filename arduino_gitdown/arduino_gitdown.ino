/*
 * Sample DrinkShield Sketch
 *
 * Used for simple standalone usuage of the drinkshield.
 * Records results at all times (no ready lights)
 *
 * Craig Smith <craig@gfxhax.com>
 */
 
#include "DrinkShield.h"

unsigned long time;

// 0.1 is the version written on the DrinkShield board
DrinkShield ds(0,1);

void setup()
{
  // Take 20 air samples when we first turn on the system
 ds.autocalibrate(20);
 // Turn on the Ready light and turn off the rest
 ds.greenLight(OFF);
 ds.redLight(ON);
 ds.lightBarLevel(0, 0);
 
 Serial.begin(9600);
}

void loop()
{
  int reading = 0;
  int max_reading = 0;
  
  if(Serial.available() > 0){   //only breathalyze when the computer asks us to
    
    delay(50); //wait for characters to come down the line

    //for now we don't care about what gets sent, just eat up all the bytes
    while(Serial.available() > 0){
      Serial.read();
    }
    

    ds.autocalibrate(20); 
    
    //enable the lines below if we don't want to autocalibrate before each reading
    /*
    for(int i = 0; i < 20; i++){
      if(i % 2)
        ds.setPlayerLights(OFF, OFF);
      else
        ds.setPlayerLights(ON, ON);
      
      delay(100);
    }
    */
    
    ds.greenLight(ON);
    ds.redLight(OFF);
    
    time = millis();
    //do 10 readings/sec for 5 seconds
    while(millis() < (time + 5000)){
      
      //these two lines will be changed once we figure out some calibration
      //val should be getReading, and light bars set accordingly
      reading = analogRead(0);
      ds.lightBarLevel(reading, 0);

      //overwrite the max reading if necessary
      if(reading > max_reading){
        max_reading = reading;
      }
      
      //wait 100ms until next reading
      delay(100);
    }
    
    Serial.println(max_reading); //return max reading from 8 sec period
    
    ds.greenLight(OFF);
    ds.redLight(ON);
    ds.lightBarLevel(0,0);
  }
}
