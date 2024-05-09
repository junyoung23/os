#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// sys_exec 함수는 새로운 프로그램을 실행합니다.
int sys_exec(const char *path, char *const argv[], char *const envp[]) {
    int status;

    status = execve(path, argv, envp); // 실제 execve() 호출
    if (status == -1) {
        perror("Exec failed");
        return -1;
    }
    return 0;
}
