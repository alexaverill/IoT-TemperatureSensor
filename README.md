# IoT-TemperatureSensor
Temperature Sensor integration with Home Assistant via MQTT


## Credentials File:
This requires a credentials file to define endpoints, passwords etc
```
#ifndef creds
#define creds
//Wifi credentials
const char *SSID="";
const char *PWD="";
// AWS credentials
const char *AWS_ROOT_CA="";
const char *AWS_PRIV_KET="";
const char *AWS_DEVICE_CERT="";
const char *AWS_ENDPOINT="";
const char *AWS_DeviceName="";
const char *DeviceLocation = "Basement";
const char *AWS_DeviceName="TestThing";

// Home Assistant credentials
const char *HA_ENDPOINT="10.0.0.38";
const char *HA_USERNAME = "";
const char *HA_PASSWORD = "";
const char *HA_DeviceName="GroundTemp";

#define AWS_IOT_PUBLISH_TOPIC   "tempSense/pub"
#define HA_PUBLISH "temp/ground/pub"
#endif
```