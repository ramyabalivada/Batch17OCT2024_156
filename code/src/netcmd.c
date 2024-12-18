#include "common.h"
 
void run_netstat_commands(int choice, char *output) {
    FILE *fp;
    char buffer[2048];  // Increased buffer size
 
    // Clear previous output
    memset(output, 0, 2048);  // Clear the output buffer with the correct size
 
    const char *cmd = NULL;
 
    switch (choice) {
        case 1:
            cmd = "netstat -s";  // Protocol Statistics
                        log_message(LOG_DEBUG, NULL);
            break;
        case 2:
            cmd = "netstat -r";  // Routing Table
                        log_message(LOG_DEBUG,"Receiving choice as 2");
            break;
        case 3:
            cmd = "netstat -tn";  // Active TCP
                        log_message(LOG_DEBUG,"Receiving choice as 3");
            break;
        case 4:
            cmd = "netstat -un";  // Active UDP
                        log_message(LOG_DEBUG,"Receiving choice as 4");
            break;
        case 5:
            cmd = "netstat -tanp | grep -i firefox";  // Internet connections (Firefox)
                        log_message(LOG_DEBUG,"Receiving choice as 5");
            break;
        case 6:
            cmd = "netstat -tanp | grep -i LISTEN";  // LISTEN connections
                        log_message(LOG_DEBUG,"Receiving choice as 6");
            break;
        default:
            log_message(LOG_WARNING, "Invalid choice");
            return;
    }
 
    fp = popen(cmd, "r");
    if (fp == NULL) {
        log_message(LOG_FATAL, "Failed to run netstat command");
        return;
    }
 
    while (fgets(buffer, sizeof(buffer), fp)) {
        strcat(output, buffer);
    }
 
    if (strlen(output) == 0) {
        strcat(output, "No output returned from netstat command.\n");
    }
 
    fclose(fp);
}
 
