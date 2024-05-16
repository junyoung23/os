#include "event_control.h"

// 여기에서 mutex와 조건 변수 cond를 정의합니다.
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void wait_for_event() {
    pthread_mutex_lock(&mutex);
    printf("Waiting for event...\n");
    pthread_cond_wait(&cond, &mutex);
    printf("Event signaled.\n");
    pthread_mutex_unlock(&mutex);
}

void signal_event() {
    pthread_mutex_lock(&mutex);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
}
