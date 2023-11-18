typedef enum{
    GAMEOP_UP = 0,
    GAMEOP_DOWN
} GameOp;

typedef struct{
    int score;
} GameConsole;

typedef struct{
    // TODO: socket connection data
    GameConsole* console;
} GameConsoleInterface;

GameConsole* console_new();
GameConsoleInterface* console_interface_new(GameConsole* g);

void console_operate(GameConsoleInterface* gi, GameOp op);
void console_update();
void console_render();

void console_interface_free(GameConsoleInterface* gi);
void console_free(GameConsole* g);
