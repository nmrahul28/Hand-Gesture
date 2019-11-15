
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

#define LED1 D5
#define LED2 D6
#define LED3 D7
#define LED4 D8

const int motor11 = D0;  
const int motor12 = D1;
const char* server = "api.thingspeak.com";
String apiKey ="DA7Y1RICK75L0HIN";     


const char* ssid = "Campus Connect CUM";      //fill in your wifi name
const char* pass = "";  //fill in your wifi password

int status = WL_IDLE_STATUS;
WiFiClient  client;
int readValue; // variable to save channel field reading 
unsigned long myChannelNumber = 305319; // modify this with your own Channel Number
const char * myReadAPIKey = "ELHNIADYXTIHOOJT";
void setup() 
{
  Serial.begin(115200); // for debugging reasons
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
  pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
      pinMode(LED3, OUTPUT);
        pinMode(LED4, OUTPUT);
        pinMode(motor11,OUTPUT);
        pinMode(motor12,OUTPUT);
        analogWrite(LED1, 0);
        analogWrite(LED2, 0);
        analogWrite(LED3, 0);
        analogWrite(LED4, 0);
}

void loop() 
{
   float h;
  // Read the latest value from field 1 of your channel
   readValue = ThingSpeak.readIntField(myChannelNumber, 1, myReadAPIKey);
  Serial.print("readValue = "); // debugging instrument
  Serial.println(readValue);    // debugging instrument
  
if ( readValue == 1)
  {
   Serial.println("MOVING FORWARD");    // debugging instrument
    analogWrite(LED1, 180);
    analogWrite(LED2, 0);
    analogWrite(LED3, 180);
    analogWrite(LED4,0); 

  }
   if ( readValue == 2)
  {
    Serial.println("MOVING REVERSE");    // debugging instrument
    analogWrite(LED1, 0);
    analogWrite(LED2, 180);
    analogWrite(LED3, 0);
     analogWrite(LED4,180); 
  }
   if ( readValue == 3)
  {
    Serial.println("MOVING LEFT");    // debugging instrument
    analogWrite(LED1, 0); 
    analogWrite(LED2, 180);
    analogWrite(LED3, 180);
    analogWrite(LED4, 0); 
   
  }
   if ( readValue == 4)
  {
       Serial.println("MOVING RIGHT");    // debugging instrument
    analogWrite(LED1, 180); 
    analogWrite(LED2, 0);
    analogWrite(LED3, 0);
    analogWrite(LED4, 180); 
  }
    if ( readValue ==0)
  {
    Serial.println("ROBOT STOPPED");    // debugging instrument
    analogWrite(LED1, 0); 
    analogWrite(LED2, 0);
    analogWrite(LED3, 0);
    analogWrite(LED4, 0); 
  }
  
  if ( readValue == 5)
  {
    Serial.println("STOP");
    digitalWrite(motor11,LOW);
    digitalWrite(motor12,LOW);
     
  }
  if ( readValue == 6)
  {
    Serial.println("open");
       digitalWrite(motor11,HIGH);
    digitalWrite(motor12,LOW);
    
  }
  if ( readValue == 7)
  {
    Serial.println("close");
         digitalWrite(motor11,LOW);
    digitalWrite(motor12,HIGH);
    
  }
}

