#include <stdlib.h>  // For exit() and abort()
#include <stdio.h>   // For fprintf()

// 프로세스 종료 함수
void sys_exit(int status) {
    // 여기에 프로세스를 종료하기 전에 필요한 자원 정리 로직을 추가할 수 있습니다.
    // 예를 들어, 열려 있는 파일을 닫거나, 메모리 할당을 해제할 수 있습니다.

    fprintf(stderr, "Exiting with status: %d\n", status);
    exit(status);
}

// 프로세스 강제 종료 함수
void sys_abort() {
    // 프로세스를 강제로 종료하기 전에 로그를 남기거나,
    // 특정 상황을 처리하는 로직을 추가할 수 있습니다.

    fprintf(stderr, "Process aborted\n");
    abort();
}
