/* src/server/main.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "netserver.h"

int main(void)
{
    net_socket_t server_fd;
    net_socket_t client_fd;
    struct sockaddr_in client_addr;
    int client_len;

    if (net_server_create(&server_fd) != NET_OK) {
        return EXIT_FAILURE;
    }

    printf("Server listening on port %d...\n", NET_PORT);

    for (;;) {
        client_len = sizeof(client_addr);
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr,
                          (socklen_t*)&client_len);

        if (client_fd < 0) {
            perror("accept failed");
            continue;
        }

        if (net_server_handle_client(client_fd) != NET_OK) {
            fprintf(stderr, "Failed to handle client\n");
        }

        close(client_fd);
    }

    net_server_cleanup(server_fd);
    return EXIT_SUCCESS;
}
