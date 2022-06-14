#ifndef TEMPERATURECLIENT_H
#define TEMPERATURECLIENT_H
#include "GeneralMQTTClient.h"
class TemperatureClient:public GeneralMQTTClient{
    public:
        TemperatureClient(char* _endpoint, int _port,char* _name,
                    char* _username, char* _password, int _updateFrequency,char *_topic,char *_location )
                    :GeneralMQTTClient(_endpoint, _port,_name,
                    _username,  _password, _updateFrequency )
        {
            topic = _topic;
            location = _location;
        }
        void sendMessage(float temperature,float humidity,float feelsLike){
            // StaticJsonDocument<256> doc;
            // doc["temperature"] = temperature;
            // doc["humidity"] = humidity;
            // doc["feelsLike"]=feelsLike;
            // doc["location"] = location;
            //publish(&doc,topic);
        }
    private:
        char *topic= "tempSense";
        char *location="location";
};
#endif