#include "event_control_test.h"
#include "event_control.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* thread_wait(void* arg) {
    printf("Thread waiting for event...\n");
    wait_for_event();
    printf("Event received, thread proceeding...\n");
    return NULL;
}

int test_event_control() {
    printf("Running event control test\n");
    pthread_t tid;
    printf("Creating thread to wait for event...\n");
    pthread_create(&tid, NULL, thread_wait, NULL);

    sleep(1);  // 스레드가 이벤트를 기다리도록 충분한 시간 제공
    printf("Signaling event...\n");
    signal_event();  // 이벤트 신호

    pthread_join(tid, NULL);  // 스레드 종료 대기
    printf("Test completed.\n");
    return 0;
}
