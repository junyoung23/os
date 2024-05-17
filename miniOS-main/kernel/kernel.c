#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "syscall.h"
#include "event_control.h"
#include <pthread.h>
#include <unistd.h>

void print_minios(char* str);
void test_syscalls();
void test_event_control();

int main() {
    print_minios("[MiniOS SSU] Hello, World!");
    char *input;

    while (1) {
        input = readline("커맨드를 입력하세요(종료:exit) : ");

        if (strcmp(input, "exit") == 0) {
            break;
        } else if (strcmp(input, "syscalls") == 0) {
            test_syscalls();
        } else if (strcmp(input, "event_control") == 0) {
            test_event_control();
        } else {
            system(input);
        }

        free(input);
    }

    print_minios("[MiniOS SSU] MiniOS Shutdown........");
    return 0;
}

void print_minios(char* str) {
    printf("%s\n", str);
}

void test_syscalls() {
    printf("Running test_syscalls\n");

    // sys_fork 테스트
    printf("Before sys_fork\n");
    int pid = sys_fork();
    printf("After sys_fork, pid: %d\n", pid);
    if (pid == 0) {
        printf("Child process, PID: %d\n", getpid());
    } else {
        printf("Parent process, PID: %d, Child PID: %d\n", getpid(), pid);
        sys_waitpid(pid, NULL, 0);
    }

    // sys_abort 테스트
    printf("Before sys_abort\n");
    sys_abort();
    printf("After sys_abort\n");
}

void* thread_wait(void* arg) {
    printf("Thread waiting for event...\n");
    wait_for_event();
    printf("Event received, thread proceeding...\n");
    return NULL;
}

void test_event_control() {
    pthread_t tid;
    printf("Creating thread to wait for event...\n");
    pthread_create(&tid, NULL, thread_wait, NULL);

    sleep(1);  // 스레드가 이벤트를 기다리도록 충분한 시간 제공
    printf("Signaling event...\n");
    signal_event();  // 이벤트 신호

    pthread_join(tid, NULL);  // 스레드 종료 대기
    printf("Test completed.\n");
}
