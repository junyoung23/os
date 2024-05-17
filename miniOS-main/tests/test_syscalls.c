#include "syscall.h"
#include <stdio.h>

int main() {
    printf("Running test_syscalls\n");

    // sys_fork 테스트
    int pid = sys_fork();
    if (pid == 0) {
        printf("Child process, PID: %d\n", getpid());
    } else {
        printf("Parent process, PID: %d, Child PID: %d\n", getpid(), pid);
        sys_waitpid(pid, NULL, 0);
    }

    // sys_abort 테스트
    sys_abort();

    return 0;
}
