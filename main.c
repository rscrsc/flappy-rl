#include<stdio.h>
#include<stdlib.h>

#include "console.h"
#include "logger.h"

#define DEMO_MODE
const float MAX_FPS = 60.0;

#define TRY(description, condition, logger_inst) \
    do { \
        logger_log(logger_inst, LOG_INFO, description "..."); \
        if(condition) { \
            logger_log(logger_inst, LOG_ERROR, description " failed."); \
            exit(1); \
        } \
        logger_log(logger_inst, LOG_INFO, description " success."); \
    } while(0)

int main(){
    Logger* l = logger_new((FILE*)stdout);
    GameConsole* g;             
    GameConsoleInterface* gi;
    
    TRY("Starting GameConsole",
                    (g = console_new()) == NULL
                , l);
    TRY("Connecting GameConsole", 
                    (gi = console_interface_new(g)) == NULL
                , l);

    #ifdef DEMO_MODE
    
    console_operate(gi, GAMEOP_UP);
    console_update();
    console_render();

    #endif

    console_interface_free(gi);
    console_free(g);
    return 0;
}
