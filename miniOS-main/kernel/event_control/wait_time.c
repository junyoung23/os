#include "system.h"
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int wait_time(int seconds) {
    printf("Waiting for %d seconds...\n", seconds);

    time_t start_time = time(NULL);
    sleep(seconds);
    time_t end_time = time(NULL);

    printf("Wait time of %d seconds completed.\n", seconds);
    printf("Start time: %s", ctime(&start_time));
    printf("End time: %s", ctime(&end_time));

    return 0;
}
