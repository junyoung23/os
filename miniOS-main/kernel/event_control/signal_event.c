#include "event_control.h"
#include <stdio.h>
#include <pthread.h>

void* signal_event_thread(void* arg) {
    pthread_mutex_lock(&mutex);  // 뮤텍스로 보호
    printf("Signaling event...\n");
    pthread_cond_signal(&cond);  // 대기 중인 스레드에게 신호
    pthread_mutex_unlock(&mutex);  // 뮤텍스 잠금 해제
    return NULL;
}

void signal_event() {
    pthread_t tid;
    pthread_create(&tid, NULL, signal_event_thread, NULL);
    pthread_detach(tid);  // 메인 스레드와 독립적으로 실행되도록 분리
}
