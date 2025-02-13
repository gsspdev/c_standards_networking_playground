/* include/client.h */
#ifndef CLIENT_H
#define CLIENT_H

#include "network.h"

typedef struct
{
    net_socket_t socket;
} client_t;

net_error_t client_init(client_t *client);
net_error_t client_connect(client_t *client);
net_error_t client_exchange_messages(client_t *client);
void client_cleanup(client_t *client);

#endif /* CLIENT_H */
