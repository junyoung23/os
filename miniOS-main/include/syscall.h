#ifndef SYSCALL_H
#define SYSCALL_H

int sys_fork(void);
int sys_exec(const char *path, char *const argv[], char *const envp[]);
void sys_exit(int status);
void sys_abort(void);

#endif
