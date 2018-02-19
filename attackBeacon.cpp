#include "attackBeacon.h"
using namespace spraybeacon;

attackBeacon::attackBeacon(string interface, string ssid)
{
    this->sender.default_interface(interface.c_str());
    this->ssid = ssid;
}

void attackBeacon::makeBeacon()
{
    // Make this a broadcast frame. Note that Dot11::BROADCAST
    // is just the same as "ff:ff:ff:ff:ff:ff"
    this->beacon.addr1(Dot11::BROADCAST);
    // We'll set the source address to some arbitrary address
    this->beacon.addr2("00:01:02:03:04:05");
    // Set the bssid, to the same one as above
    this->beacon.addr3(beacon.addr2());

    // Let's add an ssid option
    this->beacon.ssid(this->ssid.c_str());
    // Our current channel is 8
    this->beacon.ds_parameter_set(8);
    // This is our list of supported rates:
    this->beacon.supported_rates({ 1.0f, 5.5f, 11.0f });

    // Encryption: we'll say we use WPA2-psk encryption
    this->beacon.rsn_information(RSNInformation::wpa2_psk());
    // The beacon's ready to be sent!
}

void attackBeacon::sendBeacon()
{
    this->tap.inner_pdu(beacon);
    this->sender.send(this->tap);
}
