/* include/netserver.h */
#ifndef NET_SERVER_H_INCLUDED
#define NET_SERVER_H_INCLUDED

#include "netcommon.h"

/* Function prototypes */
int net_server_create(net_socket_t *server_fd);
int net_server_handle_client(net_socket_t client_fd);
void net_server_cleanup(net_socket_t server_fd);

#endif /* NET_SERVER_H_INCLUDED */
