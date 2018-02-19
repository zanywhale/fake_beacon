#include <iostream>
#include <unordered_map>
#include <unistd.h>
#include "attackBeacon.h"
#include "networkInfo.h"

using namespace std;
using namespace spraybeacon;
using namespace netinfo;

int main(int argc, char *argv[])
{
    if (argc < 3){
        fprintf(stderr, "Usage : ./fake_beacon <INTERFACE> <SSID_1> [SSID_2] ...\n");
        return 0;
    }
    else{
        // check interface
        networkInfo nif;
        nif.checkInterface(argv[1]);
    }

    static unordered_map<string, attackBeacon*>* ssidMap = new unordered_map<string, attackBeacon*>;
    static unordered_map<string, attackBeacon*>::iterator umapIter;
    attackBeacon *akb;

    for (int i = 2; i < argc; i++){
        akb = new attackBeacon(argv[1], argv[i]);
        akb->makeBeacon();
        ssidMap->insert(unordered_map<string, attackBeacon*>::value_type(argv[i], akb));
    }

    while(true){
        for ( umapIter = ssidMap->begin(); umapIter != ssidMap->end(); umapIter++){
            umapIter->second->sendBeacon();
        }
        usleep(10000);
    }

    return 0;
}
