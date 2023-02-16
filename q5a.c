
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_READERS 10
#define NUM_WRITERS 5
#define SIM_READ 3

typedef struct {
    pthread_mutex_t lock;
    pthread_cond_t read_ok;
    pthread_cond_t write_ok;
    int readers;
    int writers_waiting;
    int writers;
} rw_lock;

void rwl_init(rw_lock *lock) {
    lock->readers = 0;
    lock->writers_waiting = 0;
    lock->writers = 0;
    pthread_mutex_init(&lock->lock, NULL);
    pthread_cond_init(&lock->read_ok, NULL);
    pthread_cond_init(&lock->write_ok, NULL);
}

void rwl_destroy(rw_lock *lock) {
    pthread_mutex_destroy(&lock->lock);
    pthread_cond_destroy(&lock->read_ok);
    pthread_cond_destroy(&lock->write_ok);
}

void rwl_read_lock(rw_lock *lock) {
    pthread_mutex_lock(&lock->lock);
    while (lock->writers > 0 || (lock->writers_waiting > 0 && lock->readers >= SIM_READ)) {
        pthread_cond_wait(&lock->read_ok, &lock->lock);
    }
    lock->readers++;
    pthread_mutex_unlock(&lock->lock);
}

void rwl_read_unlock(rw_lock *lock) {
    pthread_mutex_lock(&lock->lock);
    lock->readers--;
    if (lock->readers == 0) {
        pthread_cond_signal(&lock->write_ok);
    }
    pthread_mutex_unlock(&lock->lock);
}

void rwl_write_lock(rw_lock *lock) {
    pthread_mutex_lock(&lock->lock);
    lock->writers_waiting++;
    while (lock->readers >= SIM_READ || lock->writers > 0) {
        pthread_cond_wait(&lock->write_ok, &lock->lock);
    }
    lock->writers_waiting--;
    lock->writers++;
    pthread_mutex_unlock(&lock->lock);
}

void rwl_write_unlock(rw_lock *lock) {
    pthread_mutex_lock(&lock->lock);
    lock->writers--;
    if (lock->writers == 0) {
        pthread_cond_broadcast(&lock->read_ok);
    } else {
        pthread_cond_signal(&lock->write_ok);
    }
    pthread_mutex_unlock(&lock->lock);
}

void* reader(void *arg) {
    rw_lock *lock = (rw_lock*) arg;
    while (1) {
        rwl_read_lock(lock);
        printf("Thread %ld: reading\n", pthread_self());
        sleep(1);
        rwl_read_unlock(lock);
        printf("Thread %ld: done reading\n", pthread_self());
        sleep(1);
    }
    return NULL;
}

void* writer(void *arg) {
    rw_lock *lock = (rw_lock*) arg;
    while (1) {
        rwl_write_lock(lock);
        printf("Thread %ld: writing\n", pthread_self());
        sleep(1);
        rwl_write_unlock(lock);
        printf("Thread %ld: done writing\n", pthread_self());
        sleep(1);
    }
    return NULL;
}

int main() {
    rw_lock lock;
    rwl_init(&lock);

    pthread_t readers[NUM_READERS];
    pthread_t writers[NUM_WRITERS];

    for (int i = 0; i < NUM_READERS; i++) {
        pthread_create(&readers[i], NULL, reader, &lock);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_create(&writers[i],NULL,writer,&lock);
    }
reader(readers);
writer(writers);
return 0;
}