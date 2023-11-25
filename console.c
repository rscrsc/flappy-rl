#include<stdlib.h>
#include<raylib.h>
#include "mydebug.h"
#include "console.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"

GameConsole* console_new(){
    return malloc(sizeof(GameConsole));
}
GameConsoleInterface* console_interface_new(GameConsole* g){
    GameConsoleInterface *gi = malloc(sizeof(GameConsoleInterface));
    gi->console = g;
    return gi;
}
void console_interface_free(GameConsoleInterface* gi){
    free(gi);
}
void console_free(GameConsole* g){
    free(g);
}

void console_operate(GameConsoleInterface* gi, GameOp op){
    if(op == GAMEOP_UP){
        gi->console->score += 1;
    }
}
void console_update(GameConsoleInterface* gi){
    UNIMPLEMENTED("console_update");
}
void console_render(GameConsoleInterface* gi){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText(TextFormat("SCORE: %d", gi->console->score), 10, 200, 20, MAROON);
    EndDrawing();
}
