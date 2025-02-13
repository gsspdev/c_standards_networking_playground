/* include/server.h */
#ifndef SERVER_H
#define SERVER_H

#include "network.h"

typedef struct
{
    net_socket_t socket;
    bool running;
} server_t;

net_error_t server_init(server_t *server);
net_error_t server_run(server_t *server);
void server_cleanup(server_t *server);

#endif /* SERVER_H */
