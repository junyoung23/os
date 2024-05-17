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

int createfile(const char *filename) {
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error creating file");
        return -1;
    }
    close(fd);
    return 0;
}
