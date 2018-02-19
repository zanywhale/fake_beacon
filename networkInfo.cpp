#include "networkInfo.h"
using namespace netinfo;

networkInfo::networkInfo()
{

}

void networkInfo::checkInterface(string interface)
{
    pcap_if_t *devs;
    char errbuf[PCAP_ERRBUF_SIZE];
    const char *strcheck = interface.c_str();
    int check = 0;
    if (-1 == pcap_findalldevs(&devs, errbuf))
    {
        cout << "Couldn't open device list: " << errbuf << endl;
        exit(1);
    }
    if (!devs) {
        cout << "No devices found." << endl;
        exit(1);
    }
    for (pcap_if_t *d = devs; d; d = d->next) {
        if(!strcmp(d->name, strcheck))
            check++;
    }
    pcap_freealldevs(devs);

    if(!check){
        fprintf(stderr, "\033[1;34mError : interface is not exist... Check it plz.\033[0m\n"\
                        "Usage : ./fake_beacon <INTERFACE> <SSID_1> [SSID_2] ...\n");
        exit(1);
    }
}
