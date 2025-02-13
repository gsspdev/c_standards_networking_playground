/* src/client/client.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "netclient.h"

int net_client_connect(net_socket_t *sock_fd)
{
    struct sockaddr_in server_addr;

    /* Create socket */
    *sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sock_fd < 0) {
        perror("socket failed");
        return NET_ERROR;
    }

    /* Initialize server address structure */
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(NET_PORT);

    if (inet_pton(AF_INET, NET_SERVER_ADDR, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address\n");
        close(*sock_fd);
        return NET_ERROR;
    }

    /* Connect to server */
    if (connect(*sock_fd, (struct sockaddr *)&server_addr,
                sizeof(server_addr)) < 0) {
        perror("connect failed");
        close(*sock_fd);
        return NET_ERROR;
    }

    return NET_OK;
}

int net_client_exchange(net_socket_t sock_fd)
{
    const char *message = "Hello from client";
    char buffer[NET_BUFFER_SIZE];
    int bytes_read;

    /* Send message */
    if (send(sock_fd, message, strlen(message), 0) < 0) {
        perror("send failed");
        return NET_ERROR;
    }

    /* Clear buffer */
    memset(buffer, 0, sizeof(buffer));

    /* Receive response */
    bytes_read = read(sock_fd, buffer, NET_BUFFER_SIZE - 1);
    if (bytes_read < 0) {
        perror("read failed");
        return NET_ERROR;
    }

    printf("Server response: %s\n", buffer);
    return NET_OK;
}

void net_client_cleanup(net_socket_t sock_fd)
{
    close(sock_fd);
}
