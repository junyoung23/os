#ifndef EVENT_CONTROL_H
#define EVENT_CONTROL_H

#include <pthread.h>

// 조건 변수와 뮤텍스의 선언
extern pthread_cond_t cond;
extern pthread_mutex_t mutex;

void wait_for_event();
void signal_event();

#endif // EVENT_CONTROL_H
