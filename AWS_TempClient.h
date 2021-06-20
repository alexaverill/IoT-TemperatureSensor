#ifndef AWS_TEMPCLIENT
#define AWS_TEMPCLIENT
#include<MQTTClient.h>
class AWS_TempClient:public MQTTClient{
    public:
    AWS_TEMPCLIENT(WiFiClient *_wifi, char* _endpoint, int _port,char* _name,
                    char* _username, char* _password, int _updateFrequency )
                    :MQTTClient(iFiClient *_wifi, char* _endpoint, int _port,char* _name,
                    char* _username, char* _password, int _updateFrequency )
                    {
                    }
}
#endif