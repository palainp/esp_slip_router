#ifndef _USER_CONFIG_
#define _USER_CONFIG_

typedef enum {SIG_DO_NOTHING=0, SIG_START_SERVER=2, SIG_SEND_DATA, SIG_CONSOLE_RX, SIG_CONSOLE_TX } USER_SIGNALS;

#define	ESP_SLIP_ROUTER_VERSION "V1.1.1"

#define WIFI_SSID            "ssid"
#define WIFI_PASSWORD        "password"

//
// Define the softAP configuration
// default is to not use AP mode
//
#define WIFI_AP_ENABLE          false
#define WIFI_AP_SSID            "MyAP"
#define WIFI_AP_PASSWORD        "password"

#define MAX_CLIENTS	     8

//
// Size of the console send buffer
//
#define MAX_CON_SEND_SIZE    1024

//
// Define this for debug output on the SoftUART (Rx GPIO 14, Tx GPIO 12)
//
//#define DEBUG_SOFTUART      1

//
// Define this to support the "scan" command for AP search
//
#define ALLOW_SCANNING      1

//
// Define this if you want to have access to the config console via TCP.
// Ohterwise only local access via serial is possible
//
#define REMOTE_CONFIG      1
#define CONSOLE_SERVER_PORT  7777

//
// Define the GPIO of the status LED
// If undefined, no status LED
//
#define STATUS_LED  2
#define MUX_STATUS_LED {PIN_FUNC_SELECT (PERIPHS_IO_MUX_GPIO2_U, FUNC_GPIO2);}

//
// Define a portmap from wifi address to local peer address
// on the same port. This is a helper for ADD_INITIAL_PORTMAP
//
#define ADD_PORTMAP(PROTO, PORT) \
       ip_portmap_add(PROTO, my_ip.addr, PORT, config.ip_addr_peer.addr, PORT);

//
// Add initial portmap in the ADD_INITIAL_PORTMAP macro
// If HAVE_INITIAL_PORTMAP is undefined, nothing is added
//
#define HAVE_INITIAL_PORTMAP 1
#define ADD_INITIAL_PORTMAP \
{ \
       ADD_PORTMAP(IP_PROTO_TCP, 1883); /* MQTT */    \
}

#endif
