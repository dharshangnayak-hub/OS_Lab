#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t chopstick[5];

void* philosopher(void* arg) {
    int i = (int)(long)arg;

    while (1) {
        printf("P%d is thinking\n", i);
        sleep(1);
        sem_wait(&chopstick[i]);
        sem_wait(&chopstick[(i + 1) % 5]);
        printf("P%d is EATING\n", i);
        sleep(1);
        sem_post(&chopstick[i]);
        sem_post(&chopstick[(i + 1) % 5]);
    }
}

int main() {
    pthread_t threads[5];
    for (int i = 0; i < 5; i++) 
        sem_init(&chopstick[i], 0, 1);
    for (int i = 0; i < 5; i++) 
        pthread_create(&threads[i], NULL, philosopher, (void*)(long)i);
    for (int i = 0; i < 5; i++) 
        pthread_join(threads[i], NULL);
    return 0;
}