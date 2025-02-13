/* src/client_main.c */
#include <stdio.h>
#include <stdlib.h>
#include "client.h"

int main(void)
{
    client_t client;
    net_error_t result;

    result = client_init(&client);
    if (result != NET_SUCCESS)
    {
        fprintf(stderr, "Client initialization failed: %s\n", net_strerror(result));
        return EXIT_FAILURE;
    }

    result = client_connect(&client);
    if (result != NET_SUCCESS)
    {
        fprintf(stderr, "Connection failed: %s\n", net_strerror(result));
        client_cleanup(&client);
        return EXIT_FAILURE;
    }

    result = client_exchange_messages(&client);
    if (result != NET_SUCCESS)
    {
        fprintf(stderr, "Message exchange failed: %s\n", net_strerror(result));
        client_cleanup(&client);
        return EXIT_FAILURE;
    }

    client_cleanup(&client);
    return EXIT_SUCCESS;
}
