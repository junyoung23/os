#ifndef SYSTEM_H
#define SYSTEM_H
#include <pthread.h>

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

extern pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
extern pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

#endif // SYSTEM_H
