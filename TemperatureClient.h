#ifndef TEMPERATURECLIENT
#define TEMPERATURECLIENT
#include<MQTTClient.h>
class TemperatureClient:public MQTTClient{
    public:
        TemperatureClient(WiFiClient *_wifi, char* _endpoint, int _port,char* _name,
                    char* _username, char* _password, int _updateFrequency,char *_topic,char *_location )
                    :MQTTClient(WiFiClient *_wifi, char* _endpoint, int _port,char* _name,
                    char* _username, char* _password, int _updateFrequency ))
        {
            topic = _topic;
            location = _location;
        }
        void sendMessage(float temperature,float humidity,float feelsLike){
            StaticJsonDocument<256> document;
            doc["temperature"] = temp;
            doc["humidity"] = humidity;
            doc["feelsLike"]=feelsLike;
            doc["location"] = location;
            publish(&document,topic);
        }
    private:
        char *topic= "tempSense";
        char *location="location";
}
#endif