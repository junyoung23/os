#ifndef EVENT_CONTROL_H
#define EVENT_CONTROL_H

#include <pthread.h>
#include <stdio.h>

// 조건 변수와 뮤텍스의 외부 선언
extern pthread_cond_t cond;
extern pthread_mutex_t mutex;

// 이벤트 대기 함수 선언
void wait_for_event();

// 이벤트 알림 함수 선언
void signal_event();

#endif // EVENT_CONTROL_H
