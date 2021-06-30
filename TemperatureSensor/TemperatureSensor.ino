#include "creds.h"
#include "TemperatureClient.h"

TemperatureClient tempClient(HA_ENDPOINT,1883,HA_DeviceName,HA_USERNAME,HA_PASSWORD,60000, HA_PUBLISH, DeviceLocation);

void setup()
{
	Serial.begin(115200);
}

void loop()
{
	Serial.println("Testing");
}
