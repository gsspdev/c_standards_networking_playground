/* include/netclient.h */
#ifndef NET_CLIENT_H_INCLUDED
#define NET_CLIENT_H_INCLUDED

#include "netcommon.h"

/* Function prototypes */
int net_client_connect(net_socket_t *sock_fd);
int net_client_exchange(net_socket_t sock_fd);
void net_client_cleanup(net_socket_t sock_fd);

#endif /* NET_CLIENT_H_INCLUDED */
