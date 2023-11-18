#ifndef LOGGER_H
#define LOGGER_H

typedef enum {
    LOG_INFO = 0,
    LOG_ERROR
} LogType;

typedef struct{
    FILE* output_file;
}Logger;

Logger* logger_new(FILE* output_file);

void logger_log(Logger* l, LogType t, const char* format, ...);

#endif
