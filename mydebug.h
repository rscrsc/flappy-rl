#include<stdio.h>
#define UNREACHABLE(msg) do { \
    fprintf(stderr, "===!!!UNREACHABLE: %s\n", msg); \
    exit(1); \
} while (0)

#define UNIMPLEMENTED(msg) do { \
    fprintf(stderr, "[[[UNIMPLEMENTED: %s]]]\n", msg); \
    exit(1); \
} while (0)
