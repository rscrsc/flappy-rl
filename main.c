#include<stdio.h>
#include<stdlib.h>
#include<raylib.h>

#include "console.h"
#include "mylog.h"

#define DEMO_MODE
const float MAX_FPS = 60.0;

#define TRY(description, condition, logger_inst) \
    do { \
        mylog_log(logger_inst, MYLOG_INFO, description "..."); \
        if(condition) { \
            mylog_log(logger_inst, MYLOG_ERROR, description " failed."); \
            exit(1); \
        } \
        mylog_log(logger_inst, MYLOG_INFO, description " success."); \
    } while(0)

Logger* l;

int main(){
    l = mylog_new(stdout);
    GameConsole* g;             
    GameConsoleInterface* gi;
    
    TRY("Starting GameConsole",
                    (g = console_new()) == NULL
                , l);
    TRY("Connecting GameConsole", 
                    (gi = console_interface_new(g)) == NULL
                , l);

    #ifdef DEMO_MODE

    const int screenWidth = 270;
    const int screenHeight = 480;
    SetTraceLogLevel(LOG_ERROR);

    InitWindow(screenWidth, screenHeight, "Flappy-RL Demo");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if(IsKeyPressed(KEY_SPACE)){
            console_operate(gi, GAMEOP_UP);
        }
        //console_update();
        console_render(gi);

    }
    CloseWindow();

    #endif

    console_interface_free(gi);
    console_free(g);
    return 0;
}
