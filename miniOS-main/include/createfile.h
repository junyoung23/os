#ifndef CREATEFILE_H
#define CREATEFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// close 함수의 명시적 선언
int close(int fd);

// createfile 함수의 선언
int createfile(const char *filename);

#endif // CREATEFILE_H
