
#include "common.h"

void log_message(const char *level, const char *message) {
    FILE *log_file = fopen("logfile.txt", "a");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file\n");
        exit(EXIT_FAILURE);
    }

    time_t now;
    time(&now);
    char time_str[64];
    strftime(time_str, 64, "%Y-%m-%d %H:%M:%S", localtime(&now));

    // Log message with timestamp and log level
    fprintf(log_file, "[%s] %s: %s\n", time_str, level, message);
    fclose(log_file);

    // For critical errors (FATAL), also print to stderr
    if (strcmp(level, LOG_FATAL) == 0) {
        fprintf(stderr, "[%s] %s: %s\n", time_str, level, message);
    }
}
