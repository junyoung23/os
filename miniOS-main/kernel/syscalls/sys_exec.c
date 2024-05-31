#include "system.h"
#include <stdio.h>
#include <unistd.h>

int Exec() {
    printf("Running exec...\n");
    if (execlp("/bin/ls", "ls", NULL) == -1) {
        perror("exec failed");
    }
    return 0; // 이 부분은 사실상 도달하지 않음
}
