#ifndef SYSTEM_H
#define SYSTEM_H

#include <pthread.h>
#include <sys/types.h>

extern pthread_cond_t cond;
extern pthread_mutex_t mutex;

// 전역 변수 선언
extern int child_exists;

int minisystem();
int add(char *, char *);
int Fork();
int Exec();
int Wait();
int Kill(pid_t pid, int sig);
int GetPID();
int GetPPID();
int IPC();
int Est_PI();
int RRS();
int createfile(const char *filename);
int Abort();
int Exit(int status);
int wait_time(int seconds);
void wait_for_event();
void signal_event();

#endif // SYSTEM_H
