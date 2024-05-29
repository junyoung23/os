#ifndef SYSTEM_H
#define SYSTEM_H

#include <pthread.h>

extern pthread_cond_t cond;
extern pthread_mutex_t mutex;

int minisystem();
int add(char *, char *);
int Fork();
int IPC();
int Est_PI();
int RRS();
int createfile(const char *filename);
int Exec();
int Abort();
int Exit(int status);
int wait_time(int seconds);
void wait_for_event();
void signal_event();
int Wait();
int Kill(pid_t pid, int sig)
int GetPID();
int GetPPID()

#endif // SYSTEM_H
