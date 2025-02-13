/* include/network.h */
#ifndef NETWORK_H
#define NETWORK_H

#include <stdint.h>
#include <stdbool.h>

// Configuration
#define NET_PORT 8080
#define NET_BUFFER_SIZE 1024
#define NET_BACKLOG 10
#define NET_HOST "127.0.0.1"

// Error handling
typedef enum
{
    NET_SUCCESS = 0,
    NET_ERR_SOCKET = -1,
    NET_ERR_CONNECT = -2,
    NET_ERR_BIND = -3,
    NET_ERR_LISTEN = -4,
    NET_ERR_ACCEPT = -5,
    NET_ERR_SEND = -6,
    NET_ERR_RECEIVE = -7
} net_error_t;

// Socket wrapper
typedef struct
{
    int fd;
    bool is_valid;
} net_socket_t;

// Function declarations
const char *net_strerror(net_error_t err);

#endif /* NETWORK_H */
