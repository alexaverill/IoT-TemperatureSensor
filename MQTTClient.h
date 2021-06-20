#ifndef MQTTClient
#define MQTTClient
#include<WifiClient.h>
#include<PubSubClient.h>
#include<ArduinoJson.h>
class MQTTClient{
    public:
        MQTTClient(WiFiClient *_wifi, char* _endpoint, int _port,char* _name,
                    char* _username, char* _password, int _updateFrequency ): 
                    client(_wifi),endpoint(_endpoint),port(_port),name(_name),
                    username(_username),password(_password),updateFrequency(_updateFrequency)
        {
            mqtt(&client);
            mqtt.setServer(endpoing,port);

        }
        bool connect(){
            mqtt.connect(name,username,password);
            for(auto retries =0; retries<retryAmount; retries++){
                if(mqtt.connected()){
                    return true;
                }
                mqtt.connect(name,username,password);
                delat(retyDelay);
            }
            return false;
        }
        void publish(StaticJsonDocument<256> *doc, char *topic){
            char jsonBuff[256];
            serializeJson(doc,jsonBuff);
            mqtt.publish(topic,jsonBuff);
        }
        ~MQTTClient{
            delete mqtt;
            delete client;
        }
    private:
        WifiClient *client;
        char* enpoint, name,username,password;
        int port, updateFrequency;
        PubSubClient mqtt;
        int retryDelay = 1000;
        int retryAmount = 30;
}

#endif