#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_POINTS 200000
#define NUM_THREADS 3

long incircle = 0;
long ppt; // points per thread
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // 여기서만 정의

void *MonteCarlo(void *param) {
    long incircle_thread = 0;
    unsigned int rand_state = rand();
    long i;

    for (i = 0; i < ppt; i++) {
        double x = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;
        double y = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;

        if (x * x + y * y < 1) {
            incircle_thread++;
        }
    }
    pthread_mutex_lock(&mutex);
    incircle += incircle_thread;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int Est_PI() {
    long totalpoints = NUM_POINTS;
    int thread_count = NUM_THREADS;
    ppt = totalpoints / thread_count;

    pthread_t *threads = malloc(thread_count * sizeof(pthread_t));
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    int i;

    for (i = 0; i < thread_count; i++) {
        pthread_create(&threads[i], &attr, MonteCarlo, (void *) NULL);
        pthread_join(threads[i], NULL);
        printf("\n%d. Estimated value of π: %f\n\n", i+1, (4. * (double)incircle) / ((double)ppt * thread_count));
    }
    pthread_mutex_destroy(&mutex);
    free(threads);

    return 0;
}
