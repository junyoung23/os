#include <stdio.h>
#include <stdlib.h>
#include "system.h"

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int minisystem() {
    printf("minisystem\n");
    return 0;
}

int add(char *x, char *y) {
    printf("%d + %d = %d\n", *x - '0', *y - '0', (*x - '0') + (*y - '0'));
    return 0;
}
