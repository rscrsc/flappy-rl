CC = cc
CFLAGS := -Wall -Wextra -ggdb
SRCS := main.c console.c logger.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o flappy-rl 
