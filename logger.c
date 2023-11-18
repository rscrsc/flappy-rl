#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "logger.h"
#include "mydebug.h"

Logger* logger_new(FILE* output_file){
    Logger *l = malloc(sizeof(Logger));
    l->output_file = output_file;
    return l;
}

void logger_log(Logger* l, LogType t, char* text){
    const char *type;
    switch(t){
        case LOG_INFO: type = "INFO"; break;
        case LOG_ERROR: type = "ERROR"; break;
        default: UNREACHABLE("Wrong enum value of LogType");
    }
    fprintf(l->output_file, "[%.*s] %s\n", (int)strlen(type), type, text);
    return;
}
