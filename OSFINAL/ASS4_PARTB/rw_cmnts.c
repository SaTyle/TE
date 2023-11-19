#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

/*
This program provides a possible solution for first readers-writers problem using mutex and semaphore.
I have used 10 readers and 5 writers to demonstrate the solution. You can always play with these values.
*/

sem_t wrt;                // Semaphore to control access for writers
pthread_mutex_t mutex;    // Mutex to control access to shared variables
int cnt = 1;              // Shared variable, initially set to 1
int numreader = 0;        // Number of active readers, initially 0

// Writer thread function
void *writer(void *wno)
{   
    sem_wait(&wrt);       // Wait for permission to write
    cnt = cnt * 2;        // Modify the shared variable
    printf("Writer %d modified cnt to %d\n", *((int *)wno), cnt);
    sem_post(&wrt);       // Release the lock for other writers or readers
}

// Reader thread function
void *reader(void *rno)
{   
    // Reader acquires the lock before modifying numreader
    pthread_mutex_lock(&mutex);
    numreader++;
    if (numreader == 1) {
        sem_wait(&wrt);    // If this is the first reader, block the writer
    }
    pthread_mutex_unlock(&mutex);  // Release the mutex for other readers

    // Reading Section
    printf("Reader %d: read cnt as %d\n", *((int *)rno), cnt);

    // Reader acquires the lock before modifying numreader
    pthread_mutex_lock(&mutex);
    numreader--;
    if (numreader == 0) {
        sem_post(&wrt);    // If this is the last reader, wake up the writer
    }
    pthread_mutex_unlock(&mutex);  // Release the mutex for other readers
}

int main()
{   
    pthread_t read[10], write[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt, 0, 1);

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Used for numbering readers and writers

    // Create reader threads
    for (int i = 0; i < 10; i++) {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
    }

    // Create writer threads
    for (int i = 0; i < 5; i++) {
        pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
    }

    // Join reader threads
    for (int i = 0; i < 10; i++) {
        pthread_join(read[i], NULL);
    }

    // Join writer threads
    for (int i = 0; i < 5; i++) {
        pthread_join(write[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
