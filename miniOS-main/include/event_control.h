#ifndef EVENT_CONTROL_H
#define EVENT_CONTROL_H

#include <pthread.h>

// 외부에서 사용될 변수들을 extern으로 선언
extern pthread_cond_t cond;
extern pthread_mutex_t mutex;

void wait_for_event();
void signal_event();

#endif // EVENT_CONTROL_H
