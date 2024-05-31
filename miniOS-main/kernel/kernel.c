#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include "system.h"
#include "event_control.h"

void print_minios(char* str);

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
    print_minios("[MiniOS SSU] Hello, World!");
    char *input;

    while (1) {
        input = readline("커맨드를 입력하세요(종료:exit) : ");
        if (input == NULL) {
            break;
        }

        if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        } else if (strcmp(input, "minisystem") == 0) {
            minisystem();
        } else if (strcmp(input, "add") == 0) {
            char *a = readline("첫 번째 값 : ");
            char *b = readline("두 번째 값 : ");
            add(a, b);
            free(a);
            free(b);
        } else if (strcmp(input, "fork") == 0) {
            Fork();
        } else if (strcmp(input, "exec") == 0) {
            Exec();
        } else if (strcmp(input, "abort") == 0) {
            Abort();
        } else if (strcmp(input, "exit_program") == 0) {
            int status;
            printf("Enter exit status: ");
            scanf("%d", &status);
            Exit(status);
        } else if (strcmp(input, "ipc") == 0) {
            IPC();
        } else if (strcmp(input, "est_pi") == 0) {
            Est_PI();
        } else if (strcmp(input, "rrs") == 0) {
            RRS();
        } else if (strcmp(input, "createfile") == 0) {
            char filename[256];
            printf("Enter filename: ");
            scanf("%s", filename);
            createfile(filename);
        } else if (strcmp(input, "wait_time") == 0) {
            int seconds;
            printf("Enter wait time in seconds: ");
            scanf("%d", &seconds);
            wait_time(seconds);
        } else if (strcmp(input, "wait_event") == 0) {
            wait_for_event();
        } else if (strcmp(input, "signal_event") == 0) {
            signal_event();
        } else if (strcmp(input, "kill") == 0) {
            pid_t pid;
            int sig;
            printf("Enter PID: ");
            scanf("%d", &pid);
            printf("Enter signal: ");
            scanf("%d", &sig);
            Kill(pid, sig);
        } else if (strcmp(input, "getpid") == 0) {
            GetPID();
        } else if (strcmp(input, "getppid") == 0) {
            GetPPID();
        } else if (strcmp(input, "wait") == 0) {
            Wait();
        } else if (strcmp(input, "test_process") == 0) {
            run_test_process();
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
