#include "system.h"
#include <stdio.h>

void signal_event() {
    pthread_mutex_lock(&mutex);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
    printf("Event has been signaled.\n");
}
