#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>

#define PORT 4044
#define MAX_CLIENTS 10
#define LOG_ERROR "ERROR"

// Log levels
#define LOG_FATAL "FATAL"
#define LOG_INFO  "INFO"
#define LOG_WARNING "WARNING"
#define LOG_DEBUG "DEBUG"

void log_message(const char *level, const char *message);
void run_netstat_commands(int choice, char *output);
void *handle_client(void *arg);
void print_menu(void);

#endif
