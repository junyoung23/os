#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // open 함수가 포함된 헤더 파일
#include <unistd.h> // close 함수가 포함된 헤더 파일
#include "system.h"

int createfile(const char *filename) {
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error creating file");
        return -1;
    }
    close(fd);
    return 0;
}
