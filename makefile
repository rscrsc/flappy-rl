CC = cc
CFLAGS := -Wall -Wextra -ggdb
SRCS := main.c console.c mylog.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o flappy-rl -lraylib 
