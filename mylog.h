#ifndef MYLOG_H
#define MYLOG_H

typedef enum {
    MYLOG_INFO = 0,
    MYLOG_ERROR
} LogType;

typedef struct{
    FILE* output_file;
}Logger;

Logger* mylog_new(FILE* output_file);

void mylog_log(Logger* l, LogType t, const char* format, ...);

#endif
