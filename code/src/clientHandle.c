#include "common.h"
 
void *handle_client(void *arg) {

    int client_fd = *((int *)arg);

    free(arg);
 
    char buffer[2048];

    int choice;

    char netstat_output[8192] = {0};
 
    while (1) {

        int recv_size = recv(client_fd, &choice, sizeof(choice), 0);

        if (recv_size <= 0) {

            break;

        }
 
        if (choice == 7) {

            break;  // Client chose to exit

        }
 
        run_netstat_commands(choice, netstat_output);

        send(client_fd, netstat_output, strlen(netstat_output), 0);

    }
 
    close(client_fd);

    return NULL;

}

 
