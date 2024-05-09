#include <stdio.h>  // 표준 입출력 함수를 사용하기 위해 필요
#include "syscall.h"

int main() {
    int pid = sys_fork();
    if (pid == 0) {  // 자식 프로세스
        sys_abort(); // 여기에서 abort를 호출하여 비정상 종료
    } else if (pid > 0) {  // 부모 프로세스
        printf("Parent process, forked child with PID: %d\n", pid);
    }

    return 0;
}
