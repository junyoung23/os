// tests/test_process.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "system.h"

void run_test_process() {
    printf("Starting process test...\n");

    // 프로세스 생성 (fork)
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork Failed\n");
        return;
    } else if (pid == 0) {
        // 자식 프로세스: 새로운 프로그램 실행 (exec)
        printf("In child process. PID: %d\n", getpid());
        if (execlp("/bin/echo", "echo", "Hello from child process!", NULL) == -1) {
            perror("Exec failed");
        }
        _exit(1);  // Exec 실패 시 자식 프로세스 종료
    } else {
        // 부모 프로세스: 자식 프로세스 기다림 (wait)
        printf("In parent process. PID: %d, Child PID: %d\n", getpid(), pid);
        if (Wait() == 0) {
            printf("Child process completed.\n");
        }
    }

    printf("Process test completed.\n");
}

int main() {
    run_test_process();
    return 0;
}
