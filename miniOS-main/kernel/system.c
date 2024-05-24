#include <stdio.h>
#include <stdlib.h>
#include "system.h"


int minisystem() {
    printf("minisystem\n");
    return 0;
}

int add(char *x, char *y) {
    printf("%d + %d = %d\n", *x - '0', *y - '0', (*x - '0') + (*y - '0'));
    return 0;
}
