#include<stdlib.h>
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
    UNIMPLEMENTED("console_operate");
}
void console_update(){
    UNIMPLEMENTED("console_update");
}
void console_render(){
    UNIMPLEMENTED("console_render");
}
