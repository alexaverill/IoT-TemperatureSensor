#ifndef HA_TEMPCLIENT
#define HA_TEMPCLIENT
#include<MQTTClient.h>
class HA_TempClient:public MQTTClient{
    public:
        HA_TEMPCLIENT(WiFiClient *_wifi, char* _endpoint, int _port,char* _name,
                    char* _username, char* _password, int _updateFrequency )
                    :MQTTClient(iFiClient *_wifi, char* _endpoint, int _port,char* _name,
                    char* _username, char* _password, int _updateFrequency )
                    {
                    }
}
#endif