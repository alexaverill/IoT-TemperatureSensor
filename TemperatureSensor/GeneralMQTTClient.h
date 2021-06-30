#ifndef GENERALMQTTCLIENT_H
#define GENERALMQTTCLIENT_H

#include<WiFiClient.h>
#include<PubSubClient.h>
#include<ArduinoJson.h>

class GeneralMQTTClient{
    public:
        GeneralMQTTClient(char* _endpoint, int _port,char* _name,
                    char* _username, char* _password, int _updateFrequency ):
                    endpoint(_endpoint),port(_port),name(_name),
                    username(_username),password(_password),updateFrequency(_updateFrequency)
        {
            mqtt.setClient(client);
            mqtt.setServer(endpoint,port);

        }
        bool connect(){
            if(mqtt.connected()) { return false;}
            mqtt.connect(name,username,password);
            for(auto retries =0; retries<retryAmount; retries++){
                if(mqtt.connected()){
                    return true;
                }
                mqtt.connect(name,username,password);
                delay(retryDelay);
            }
            return false;
        }
        void publish(StaticJsonDocument<256> *doc, char *topic){
            connect();
            char jsonBuff[256];
            //serializeJson(&doc,jsonBuff);
            //mqtt.publish(topic,jsonBuff);
        }
    private:
        WiFiClient client = WiFiClient();
        char* endpoint;
        char *name;
        char *username;
        char *password;
        int port, updateFrequency;
        PubSubClient mqtt;
        int retryDelay = 1000;
        int retryAmount = 30;
};

#endif