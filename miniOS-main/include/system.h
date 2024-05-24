#ifndef SYSTEM_H
#define SYSTEM_H

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

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

#endif // SYSTEM_H
