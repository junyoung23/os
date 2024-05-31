#include "system.h"
#include <stdio.h>

// extern 선언을 통해 다른 파일에 정의된 변수를 참조
extern pthread_cond_t cond;
extern pthread_mutex_t mutex;

void wait_for_event() {
    pthread_mutex_lock(&mutex);
    printf("Waiting for event...\n");
    pthread_cond_wait(&cond, &mutex);
    printf("Event signaled.\n");
    pthread_mutex_unlock(&mutex);
}
