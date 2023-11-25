#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>
#include "mylog.h"
#include "mydebug.h"

Logger* mylog_new(FILE* output_file){
    Logger *l = malloc(sizeof(Logger));
    l->output_file = output_file;
    return l;
}

void mylog_log(Logger* l, LogType t, const char* format, ...){
    va_list args;
    va_start(args, format);
    const char *type;
    switch(t){
        case MYLOG_INFO: type = "INFO"; break;
        case MYLOG_ERROR: type = "ERROR"; break;
        default: UNREACHABLE("Wrong enum value of LogType");
    }
    fprintf(l->output_file, "[%.*s] ", (int)strlen(type), type);
    vfprintf(l->output_file, format, args);
    fprintf(l->output_file, "\n");
    return;
}
