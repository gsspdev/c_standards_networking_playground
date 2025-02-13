/* src/client.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "client.h"

net_error_t client_init(client_t *client)
{
    client->socket.fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket.fd < 0)
    {
        return NET_ERR_SOCKET;
    }

    client->socket.is_valid = true;
    return NET_SUCCESS;
}

net_error_t client_connect(client_t *client)
{
    struct sockaddr_in server_addr = {0};

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(NET_PORT);

    if (inet_pton(AF_INET, NET_HOST, &server_addr.sin_addr) <= 0)
    {
        return NET_ERR_CONNECT;
    }

    if (connect(client->socket.fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        return NET_ERR_CONNECT;
    }

    return NET_SUCCESS;
}

net_error_t client_exchange_messages(client_t *client)
{
    const char message[] = "Hello from client";
    char buffer[NET_BUFFER_SIZE] = {0};
    ssize_t bytes_read;

    if (send(client->socket.fd, message, strlen(message), 0) < 0)
    {
        return NET_ERR_SEND;
    }

    bytes_read = recv(client->socket.fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0)
    {
        return NET_ERR_RECEIVE;
    }

    printf("Server response: %s\n", buffer);
    return NET_SUCCESS;
}

void client_cleanup(client_t *client)
{
    if (client->socket.is_valid)
    {
        close(client->socket.fd);
        client->socket.is_valid = false;
    }
}
