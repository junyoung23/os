#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "system.h"

int Wait() {
    int status;
    pid_t pid = wait(&status);
    if (pid == -1) {
        perror("wait failed");
        return 1;
    }
    printf("Child process %d terminated with status %d\n", pid, status);
    return 0;
}
