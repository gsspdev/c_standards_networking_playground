/* include/netcommon.h */
#ifndef NET_COMMON_H_INCLUDED
#define NET_COMMON_H_INCLUDED

/* Constants */
#define NET_PORT 8080
#define NET_BUFFER_SIZE 1024
#define NET_BACKLOG 10
#define NET_SERVER_ADDR "127.0.0.1"

/* Error codes */
#define NET_OK 0
#define NET_ERROR (-1)

/* Type definitions */
typedef int net_socket_t;

#endif /* NET_COMMON_H_INCLUDED */

