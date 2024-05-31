#include "system.h"
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// 전역 변수 선언
int child_exists = 0;

int Fork() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } else if (pid == 0) {
        // 자식 프로세스 코드
        execlp("/bin/ls", "ls", NULL);
    } else {
        // 부모 프로세스 코드
        child_exists = 1; // 자식 프로세스가 생성되었음을 표시
    }

    return 0;
}
