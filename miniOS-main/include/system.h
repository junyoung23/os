#ifndef SYSTEM_H
#define SYSTEM_H

int minisystem();
int add(char *, char *);
int Fork();
int IPC();
int Est_PI();
int RRS();
int createfile(const char *filename);

// Test functions
int test_syscalls();
int test_event_control();

#endif // SYSTEM_H
