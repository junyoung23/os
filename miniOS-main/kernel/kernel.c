#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include "system.h"

void print_minios(char* str);

int main() {
    print_minios("[MiniOS SSU] Hello, World!");
    char *input;

    while (1) {
        input = readline("커맨드를 입력하세요(종료:exit) : ");

        if (strcmp(input, "exit") == 0) {
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
        } else if (strcmp(input, "exit_program") == 0) { // "exit"는 프로그램 종료로 사용되므로 "exit_program"으로 변경
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
