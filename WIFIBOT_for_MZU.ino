
/*
 *  This sketch demonstrates how to set up a simple HTTP-like server.
 *  The server will set a GPIO pin depending on the request
 *    http://server_ip/gpio/0 will set the GPIO2 low,
 *    http://server_ip/gpio/1 will set the GPIO2 high
 *  server_ip is the IP address of the ESP8266 module, will be 
 *  printed to Serial when the module is connected.
 */

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
//#include <EEPROM.h>
const char* ssid = "ZWiFi";
const char* password = "opensaysz@!2012";

// Create an instance of the server
// specify the port to listatlen on as an argument

ESP8266WebServer server(80);
void setup() 
{
  Serial.begin(115200);
  delay(10);

  // prepare GPIO2
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);

  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  
  digitalWrite(D5, LOW);// at start turn off the GPIO 
  digitalWrite(D6, LOW);// at start turn off the GPIO
  digitalWrite(D7, LOW);// at start turn off the GPIO 
  digitalWrite(D8, LOW);// at start turn off the GPIO

  digitalWrite(D0, LOW);// at start turn off the GPIO 
  digitalWrite(D1, LOW);// at start turn off the GPIO
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  createWebServer();
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}
int gpioStatus=0;

void createWebServer()
{
    server.on("/F", []()
    {
      gpioStatus=1;
      Serial.println("F");
      digitalWrite(D5, LOW);
      digitalWrite(D6, HIGH);
      digitalWrite(D7, LOW);
      digitalWrite(D8, HIGH);
      server.send(200, "text", "Forward");
    });
    server.on("/B", []()
    {
      Serial.println("B");
      gpioStatus=1;
      digitalWrite(D5, HIGH);
      digitalWrite(D6, LOW);
      digitalWrite(D7, HIGH);
      digitalWrite(D8, LOW);
      server.send(200, "text", "BackWord");
    });
     server.on("/L", []()
     {
      Serial.println("L");
      gpioStatus=1;
      digitalWrite(D5, LOW);
      digitalWrite(D6, HIGH);
      digitalWrite(D7, HIGH);
      digitalWrite(D8, LOW);
      server.send(200, "text", "LEFT TURN");
    });
     server.on("/R", []()
     {
      Serial.println("R");
      gpioStatus=1;
      digitalWrite(D5, HIGH);
      digitalWrite(D6, LOW);
      digitalWrite(D7, LOW);
      digitalWrite(D8, HIGH);
      server.send(200, "text", "RIGHT TURN");
    });
    server.on("/S", []() 
     {
      Serial.println("S");
      gpioStatus=1;
      digitalWrite(D5, LOW);
      digitalWrite(D6, LOW);
      digitalWrite(D7, LOW);
      digitalWrite(D8, LOW);
      server.send(200, "text", "BackWord");
    });
    //////////////////////////////////////////////
     
    server.on("/6", []() 
     {
      Serial.println("6");
      gpioStatus=1;
      digitalWrite(D0, HIGH );
      digitalWrite(D1, LOW);
      
      server.send(200, "text", "OPEN");
    });
       
  }
 
void loop() 
{
  // Check if a client has connected
  server.handleClient();
}
