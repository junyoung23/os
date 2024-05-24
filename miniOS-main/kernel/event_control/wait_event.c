#include "event_control.h"
#include <stdio.h>
#include <unistd.h>  // for sleep

void wait_for_event() {
    pthread_mutex_lock(&mutex);  // 뮤텍스로 보호
    printf("Waiting for event...\n");

    // 시뮬레이션을 위해 잠시 대기한 후 신호를 보냄
    sleep(1);
    pthread_cond_signal(&cond);

    pthread_cond_wait(&cond, &mutex);  // 조건 변수를 사용해 대기
    printf("Event signaled.\n");
    pthread_mutex_unlock(&mutex);  // 뮤텍스 잠금 해제
}
