#include "system.h"
#include <stdio.h>

// extern 선언을 통해 다른 파일에 정의된 변수를 참조
extern pthread_cond_t cond;
extern pthread_mutex_t mutex;

void signal_event() {
    pthread_mutex_lock(&mutex);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
    printf("Event has been signaled.\n");
}
