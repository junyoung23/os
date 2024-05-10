#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

// sys_fork 함수는 자식 프로세스를 생성하고, 자식과 부모의 PID를 출력합니다.
int sys_fork(void) {
    pid_t pid;
    pid = fork(); // 실제 fork() 호출

    if (pid == -1) {
        // fork 실패 시
        perror("Fork failed");
        return -1;
    }
    else if (pid == 0) {
        // 자식 프로세스에서 실행될 코드
        printf("Child process, PID: %d\n", getpid());
    }
    else {
        // 부모 프로세스에서 실행될 코드
        printf("Parent process, PID: %d, Child PID: %d\n", getpid(), pid);
    }

    return pid; // 부모는 자식의 PID를, 자식은 0을 반환
}
