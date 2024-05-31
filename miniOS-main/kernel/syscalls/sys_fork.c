#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "system.h"

int Fork() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } else if (pid == 0) {
        execlp("/bin/ls", "ls", NULL);
    } else {
        wait(NULL); // 부모 프로세스가 자식 프로세스의 종료를 기다림
        printf("Child Complete\n");
    }

    return 0;
}
 