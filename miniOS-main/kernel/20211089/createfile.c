#include "createfile.h"

int createfile(const char *filename) {
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error creating file");
        return -1;
    }
    close(fd);
    return 0;
}
