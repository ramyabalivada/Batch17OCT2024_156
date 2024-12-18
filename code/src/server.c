#include "common.h"
 
int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t thread_id;
 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        log_message(LOG_FATAL, "Socket creation failed");
        exit(EXIT_FAILURE);
    }
 
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
 
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        log_message(LOG_FATAL, "Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
 
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        log_message(LOG_FATAL, "Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
 
    log_message(LOG_INFO, "Server listening on port...");
        printf("\nListening to clients now \n");
    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
        if (client_fd < 0) {
            log_message(LOG_ERROR, "Client connection failed");
            continue;
        }
                printf("Client connected\n");
 
        log_message(LOG_INFO, "Client connected");
        int *client_fd_ptr = malloc(sizeof(int));
        *client_fd_ptr = client_fd;
 
        if (pthread_create(&thread_id, NULL, handle_client, client_fd_ptr) != 0) {
            log_message(LOG_ERROR, "Failed to create thread for client");
            close(client_fd);
        }
 
        pthread_detach(thread_id);
    }
 
    close(server_fd);
    log_message(LOG_INFO, "Server socket closed");
 
    return 0;
}

