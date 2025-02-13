/* src/server_main.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "server.h"

static server_t server;

static void handle_signal(int signum)
{
    (void)signum;
    server.running = false;
}

int main(void)
{
    net_error_t result;

    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    result = server_init(&server);
    if (result != NET_SUCCESS)
    {
        fprintf(stderr, "Server initialization failed: %s\n", net_strerror(result));
        return EXIT_FAILURE;
    }

    result = server_run(&server);
    if (result != NET_SUCCESS)
    {
        fprintf(stderr, "Server runtime error: %s\n", net_strerror(result));
        server_cleanup(&server);
        return EXIT_FAILURE;
    }

    server_cleanup(&server);
    return EXIT_SUCCESS;
}
