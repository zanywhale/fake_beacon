#ifndef ATTACKBEACON_H
#define ATTACKBEACON_H

#include <iostream>
#include <tins/tins.h>
using namespace std;
using namespace Tins;

namespace spraybeacon{
    class attackBeacon{
    public:
        attackBeacon(string interface, string ssid);
        ~attackBeacon(){}
        void makeBeacon();
        void sendBeacon();

    private:
        Dot11Beacon beacon;
        RadioTap tap;
        PacketSender sender;
        string ssid;
    };
}

#endif // ATTACKBEACON_H
