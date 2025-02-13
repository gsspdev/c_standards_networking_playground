/* src/server/server.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "netserver.h"

int net_server_create(net_socket_t *server_fd)
{
    struct sockaddr_in server_addr;
    int opt;

    /* Create socket */
    *server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (*server_fd < 0) {
        perror("socket failed");
        return NET_ERROR;
    }

    /* Set socket options */
    opt = 1;
    if (setsockopt(*server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt failed");
        close(*server_fd);
        return NET_ERROR;
    }

    /* Initialize server address structure */
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(NET_PORT);

    /* Bind socket */
    if (bind(*server_fd, (struct sockaddr *)&server_addr,
            sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(*server_fd);
        return NET_ERROR;
    }

    /* Listen for connections */
    if (listen(*server_fd, NET_BACKLOG) < 0) {
        perror("listen failed");
        close(*server_fd);
        return NET_ERROR;
    }

    return NET_OK;
}

int net_server_handle_client(net_socket_t client_fd)
{
    char buffer[NET_BUFFER_SIZE];
    const char *response = "Hello from server";
    int bytes_read;

    /* Clear buffer */
    memset(buffer, 0, sizeof(buffer));

    /* Read client message */
    bytes_read = read(client_fd, buffer, NET_BUFFER_SIZE - 1);
    if (bytes_read < 0) {
        perror("read failed");
        return NET_ERROR;
    }

    printf("Message from client: %s\n", buffer);

    /* Send response */
    if (send(client_fd, response, strlen(response), 0) < 0) {
        perror("send failed");
        return NET_ERROR;
    }

    return NET_OK;
}

void net_server_cleanup(net_socket_t server_fd)
{
    close(server_fd);
}
