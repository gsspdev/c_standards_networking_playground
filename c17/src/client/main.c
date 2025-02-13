/* src/client/main.c */
#include <stdio.h>
#include <stdlib.h>
#include "netclient.h"

int main(void)
{
    net_socket_t sock_fd;

    if (net_client_connect(&sock_fd) != NET_OK) {
        return EXIT_FAILURE;
    }

    if (net_client_exchange(sock_fd) != NET_OK) {
        net_client_cleanup(sock_fd);
        return EXIT_FAILURE;
    }

    net_client_cleanup(sock_fd);
    return EXIT_SUCCESS;
}
