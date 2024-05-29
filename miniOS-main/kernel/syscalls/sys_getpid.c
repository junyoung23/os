#include <stdio.h>
#include <unistd.h>
#include "system.h"

int GetPID() {
    pid_t pid = getpid();
    printf("Current process ID: %d\n", pid);
    return pid;
}
