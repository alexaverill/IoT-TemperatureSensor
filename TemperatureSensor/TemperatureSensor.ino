#include "creds.h"
#include "TemperatureClient.h"
#include<WiFi.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <DHT.h>
#include <Button2.h>

#define DHTPIN 17
#define DHTTYPE DHT22
#define TITLESIZE 2
#define NUMSIZE 4
#define BUTTON_PIN 35

TFT_eSPI screen = TFT_eSPI();
DHT dht(DHTPIN, DHTTYPE);

//Setup for button to toggle screen on or off.
Button2 button = Button2(BUTTON_PIN);
#define TTGO_BACKLIGHT 4
bool lightOn = true;
void setBackLight(bool state)
{
	digitalWrite(TTGO_BACKLIGHT, (lightOn ? HIGH : LOW));
}
void toggleBacklight()
{
	lightOn = !lightOn;
	setBackLight(lightOn);
}
void clicked(Button2 &btn)
{
	toggleBacklight();
}

TemperatureClient *tempClient;

long delayTime = (60 * 1) * 1000;
bool firstRun = true;

void init()
{
	screen.init();
	screen.setRotation(0);
	dht.begin();
	setBackLight(true);
	button.setTapHandler(clicked);
}

void connectToWifi()
{
	Serial.print("Connect to wifi");
	Serial.println(SSID);
	WiFi.begin(SSID, PWD);
	while (WiFi.status() != WL_CONNECTED)
	{
		Serial.println("Not Connected");
		delay(500);
		// we can even make the ESP32 to sleep
	}
	Serial.print("Connected - ");
}

void setup()
{
	
	Serial.begin(115200);
	Serial.println("Starting");
  updateScreen(&screen,1,1,1);
	init();
	connectToWifi();
  //tempClient = new TemperatureClient(HA_ENDPOINT, 1883, HA_DeviceName, HA_USERNAME, HA_PASSWORD, 60000, HA_PUBLISH, DeviceLocation);
}
//TODO consider encapsulating screen functions into a seperate class.
void updateScreen(TFT_eSPI* screenRef,float humidity,float temperature,float heatIndex){
  Serial.println("Updating Screen!");
  screenRef->fillScreen(TFT_BLACK);
  screenRef->setCursor(0,0,1);
  
  screenRef->setTextColor(TFT_YELLOW,TFT_YELLOW);
  screenRef->setTextFont(1);
  screenRef->setTextSize(TITLESIZE);
  screenRef->println("Temperature");
  screenRef->setTextSize(NUMSIZE);
  screenRef->setTextFont(2);
  screenRef->println(String(temperature,1));
  screenRef->setTextSize(TITLESIZE);
  screenRef->setTextFont(1);
  screenRef->println("Humidity");
  screenRef->setTextSize(NUMSIZE);
  screenRef->setTextFont(2);
  screenRef->println(String(humidity,1));
  screenRef->setTextSize(TITLESIZE);
  screenRef->setTextFont(1);
  screenRef->println("Feels Like");
  screenRef->setTextFont(2);
  screenRef->setTextSize(NUMSIZE);
  screenRef->println(String(heatIndex,1));
  

}

float lastTemp, lastHumidity = 0;
long lastTime = 0;

void loop()
{
  long now = millis();
  if(firstRun || (now - lastTime) >delayTime){
    if(firstRun){
      Serial.println("First Run");
    }
    Serial.println("Updating");
   float h = dht.readHumidity();
   float t = dht.readTemperature(true);
   float hI = dht.computeHeatIndex(t,h);
   if(lastTemp != t || lastHumidity != h ){
    
    updateScreen(&screen,h,t,hI);
    lastTemp = t;
    lastHumidity = h;
    
   }
    tempClient->sendMessage(t,h,hI);
    lastTime=millis();
    firstRun = false;
   }
   button.loop();
}
