#include "event_control.h"
#include <stdio.h>
#include <pthread.h>

void* wait_for_event_thread(void* arg) {
    pthread_mutex_lock(&mutex);  // 뮤텍스로 보호
    printf("Waiting for event...\n");
    pthread_cond_wait(&cond, &mutex);  // 조건 변수를 사용해 대기
    printf("Event signaled.\n");
    pthread_mutex_unlock(&mutex);  // 뮤텍스 잠금 해제
    return NULL;
}

void wait_for_event() {
    pthread_t tid;
    pthread_create(&tid, NULL, wait_for_event_thread, NULL);
    pthread_detach(tid);  // 메인 스레드와 독립적으로 실행되도록 분리
}
