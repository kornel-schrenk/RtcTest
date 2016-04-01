#include "DS3231.h"
#include "Wire.h"

DS3231 Clock;
bool Century=false;
bool h12 = false;
bool PM = false;

void setup() {  
  // Start the I2C interface
  Wire.begin();

  //Setup the time - Use the ONLY once for initialization!!!
//  Clock.setSecond(00);//Set the second 
//  Clock.setMinute(10);//Set the minute 
//  Clock.setHour(9);  //Set the hour 
//  Clock.setDoW(5);    //Set the day of the week
//  Clock.setDate(1);  //Set the date of the month
//  Clock.setMonth(4);  //Set the month of the year
//  Clock.setYear(16);  //Set the year (Last two digits of the year)

  // Start the serial interface
  Serial.begin(9600);
}

void loop() {  
  readTime();
  delay(1000);
}

void ReadDS3231()
{
  Serial.print('\n');
  Serial.print("20");
  Serial.print(Clock.getYear(), DEC);
  Serial.print('-');
  Serial.print(Clock.getMonth(Century), DEC);
  Serial.print('-');
  Serial.print(Clock.getDate(), DEC);
  Serial.print(' ');
  Serial.print(Clock.getHour(), DEC);
  Serial.print(':');
  Serial.print(Clock.getMinute(), DEC);
  Serial.print(':');
  Serial.print(Clock.getSecond(), DEC);
  Serial.print('\n');
}

void readTime()
{
  byte year, month, date, DoW, hour, minute, second;
  Clock.getTime(year, month, date, DoW, hour, minute, second);

  Serial.print("20");
  if (year < 10) {
    Serial.print("0");    
  } 
  Serial.print(year, DEC);  
  Serial.print("-");
  if (month < 10) {
    Serial.print("0");    
  }   
  Serial.print(month, DEC);
  Serial.print("-");
  if (date < 10) {
    Serial.print("0");    
  }   
  Serial.print(date, DEC);
  
  Serial.print(' ');
  
  if (hour < 10) {
    Serial.print("0");    
  } 
  Serial.print(hour, DEC);      
  Serial.print(":");
  if (minute < 10) {
    Serial.print("0");    
  }
  Serial.print(minute, DEC);  
  Serial.print(":");
  if (second < 10) {
    Serial.print("0");    
  }
  Serial.println(second, DEC);
}

