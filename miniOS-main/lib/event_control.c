#include "event_control.h"

// 조건 변수와 뮤텍스의 정의
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// 이벤트 대기 함수 구현
void wait_for_event() {
    pthread_mutex_lock(&mutex);  // 뮤텍스로 보호
    printf("Waiting for event...\n");
    pthread_cond_wait(&cond, &mutex);  // 조건 변수를 사용해 대기
    printf("Event signaled.\n");
    pthread_mutex_unlock(&mutex);  // 뮤텍스 잠금 해제
}

// 이벤트 알림 함수 구현
void signal_event() {
    pthread_mutex_lock(&mutex);  // 뮤텍스로 보호
    pthread_cond_signal(&cond);  // 대기 중인 스레드에게 신호
    pthread_mutex_unlock(&mutex);  // 뮤텍스 잠금 해제
}
