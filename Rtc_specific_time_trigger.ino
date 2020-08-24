/*
 This program is designed to turn On and Off relay at multiple specified time 
 using DS3231 RTC module. 
 You can use, modify and deploy this program "as is" at your own discretion 
 and risks. if you want to see more Arduino projects, visit my YouTube channel
 www.youtube.com/myonline88  

 Ph Vlogline
 8/19/2020
*/

#include <RTClib.h> // for the RTC
#include <Wire.h>

// Instance of the class for RTC
RTC_DS3231 rtc;

char t[32];

// Define check in time
const int ONHour1 = 7;
const int ONMinute1 =30;
const int OFFHour1 = 8;
const int OFFMinute1 = 30;
//////////////////////////////////
const int ONHour2 = 11;
const int ONMinute2 =49;
const int OFFHour2 = 12;
const int OFFMinute2 = 40;
//////////////////////////////////
const int ONHour3 = 13;
const int ONMinute3 =30;
const int OFFHour3 = 14;
const int OFFMinute3 = 30;
//////////////////////////////////
const int ONHour4 = 16;
const int ONMinute4 =30;
const int OFFHour4 = 17;
const int OFFMinute4 = 30;
//////////////////////////////////
const int ONHour5 = 19;
const int ONMinute5 =30;
const int OFFHour5 = 20;
const int OFFMinute5 = 32;

int CurrentHour;
int CurrentMinute;
// Pins for LEDs and buzzer

const int relay1 = 8;
const int led = 10;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();

 if(rtc.lostPower()) {
   rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));  
 }

   pinMode(relay1, OUTPUT);
   pinMode(led, OUTPUT);  
   digitalWrite(relay1,LOW); 
   digitalWrite(led,LOW); 
}
void loop() {
 DateTime now = rtc.now();
   // Save check in time;
  sprintf(t, "%02d:%02d:%02d   %02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.month(), now.day(), now.year());  
   
  CurrentHour = now.hour();
  CurrentMinute = now.minute();

  Serial.print(F("Date/Time:   "));
  Serial.print(t);
  
  Serial.print("\tHour: ");
  Serial.print(CurrentHour);
  Serial.print("\tMinute: ");
  Serial.println(CurrentMinute);

if((CurrentHour==ONHour1) && (CurrentMinute == ONMinute1)){
    digitalWrite(relay1,HIGH);
    digitalWrite(led,HIGH);
//    Serial.println("INTERNET ON");
    }
if((CurrentHour==OFFHour1) && (CurrentMinute == OFFMinute1)){
      digitalWrite(relay1,LOW);
      digitalWrite(led,LOW);
//      Serial.println("INTERNET OFF");
    }

if((CurrentHour==ONHour2) && (CurrentMinute == ONMinute2)){
    digitalWrite(relay1,HIGH);
    digitalWrite(led,HIGH);
//   Serial.println("INTERNET ON");
    }
if((CurrentHour==OFFHour2) && (CurrentMinute == OFFMinute2)){
      digitalWrite(relay1,LOW);
      digitalWrite(led,LOW);
//      Serial.println("INTERNET OFF");
}
if((CurrentHour==ONHour3) && (CurrentMinute == ONMinute3)){
    digitalWrite(relay1,HIGH);
    digitalWrite(led,HIGH);
//    Serial.println("INTERNET ON");
}
if((CurrentHour==OFFHour3) && (CurrentMinute == OFFMinute3)){
      digitalWrite(relay1,LOW);
      digitalWrite(led,LOW);
//      Serial.println("INTERNET OFF");
 }
if((CurrentHour==ONHour4) && (CurrentMinute == ONMinute4)){
    digitalWrite(relay1,HIGH);
    digitalWrite(led,HIGH);
//    Serial.println("INTERNET ON");
}
if((CurrentHour==OFFHour4) && (CurrentMinute == OFFMinute4)){
      digitalWrite(relay1,LOW);
      digitalWrite(led,LOW);
//      Serial.println("INTERNET OFF");
 }
if((CurrentHour==ONHour5) && (CurrentMinute == ONMinute5)){
      digitalWrite(relay1,HIGH);
      digitalWrite(led,HIGH);
//      Serial.println("INTERNET ON");
 }
 if((CurrentHour==OFFHour5) && (CurrentMinute == OFFMinute5)){
      digitalWrite(relay1,LOW);
      digitalWrite(led,LOW);
//      Serial.println("INTERNET OFF");
 }

}


