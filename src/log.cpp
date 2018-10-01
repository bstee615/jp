#include "log.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static FILE *log_stream = NULL;

void start_log()
{
    #ifdef DEBUG
    log_stream = stdout;
    #else
    log_stream = fopen("log.txt", "w");
    #endif
}

void close_log()
{
    if (log_stream && log_stream != stdout)
    {
        fclose(log_stream);
    }
}

void lprintf(const char *fmt, ...)
{
    if (!log_stream) {
        printf("Error: log stream not initialized! Call start_log() before logging.\n");
        exit(1);
    }

    va_list arg;

    va_start(arg, fmt);
    vfprintf(log_stream, fmt, arg);
    va_end(arg);
}