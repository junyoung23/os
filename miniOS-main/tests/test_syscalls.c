#include <stdio.h>
#include "syscall.h"

int main() {
    // Fork 테스트
    int pid = sys_fork();
    if (pid == 0) {  // 자식 프로세스
        char *args[] = {"/bin/echo", "Hello from exec!", NULL};
        char *env[] = {NULL};
        sys_exec("/bin/echo", args, env);
    } else if (pid > 0) {  // 부모 프로세스
        printf("Parent process, forked child with PID: %d\n", pid);
    }

    // Exit 테스트
    if (pid != 0) {  // 부모 프로세스에서 실행
        sys_exit(0);
    }

    // Abort 테스트
    // 이 함수를 호출하면 프로그램이 비정상 종료됩니다.
    // sys_abort();

    return 0;
}
