#include "system.h"
#include <stdio.h>

extern pthread_cond_t cond;
extern pthread_mutex_t mutex;

void signal_event() {
    pthread_mutex_lock(&mutex);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
    printf("Event has been signaled.\n");
}
