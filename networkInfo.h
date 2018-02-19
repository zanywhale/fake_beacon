#ifndef NETWORKINFO_H
#define NETWORKINFO_H

#include <pcap.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

namespace netinfo{
    class networkInfo
    {
    public:
        networkInfo();
        void checkInterface(string interface);
    };
}
#endif // NETWORKINFO_H
