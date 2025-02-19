#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t lock;

int buffersize = 10, buffer_counter = 0;
int display_counter=0;
int buffer[100];
int val=1;
int shouldrun=1;

void* update() 
{
    while (shouldrun) 
    {
        pthread_mutex_lock(&lock);
        
        if (buffer_counter < buffersize) 
        {
            val=rand()%100;
            buffer[buffer_counter] = val;
            printf("Updated buffer[%d] to %d\n", buffer_counter, buffer[buffer_counter]);
            buffer_counter++;
        } 
        else 
        {
            buffer_counter = 0;
            printf("Buffer is full, resetting counter to 0\n");
        }

        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

void* display() 
{
    sleep(5);
    while (shouldrun) 
    {
        pthread_mutex_lock(&lock);

        if (display_counter<buffersize) 
        {
            printf("Generated value is %d from buffer[%d]\n", buffer[display_counter],display_counter );
            display_counter=display_counter+1;
        }
        else
        {
            printf("Nothing to print in the buffer.\n");
            display_counter=0;
        }

        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_mutex_init(&lock, NULL);

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, update, NULL);
    pthread_create(&thread2, NULL, display, NULL);

    // while(val<100)
    // {
    //     sleep(1);
    // }
    // shouldrun=0;

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}
