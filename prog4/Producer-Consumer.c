#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUF_SIZE 4
#define ITEMS 10

int buf[BUF_SIZE];
int in = 0, out = 0;
sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *arg) {
    for (int i = 1; i <= ITEMS; ++i) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buf[in] = i;
        printf("Produced: %d (pos %d)\n", i, in);
        in = (in + 1) % BUF_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        usleep(100000);
    }
    return NULL;
}

void *consumer(void *arg) {
    for (int i = 1; i <= ITEMS; ++i) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int v = buf[out];
        printf("Consumed: %d (pos %d)\n", v, out);
        out = (out + 1) % BUF_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        usleep(150000);
    }
    return NULL;
}

int main(void) {
    pthread_t p, c;
    sem_init(&empty, 0, BUF_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    return 0;
}