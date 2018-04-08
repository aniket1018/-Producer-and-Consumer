#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>

int arr[5];
int a,b;

sem_t mutex;
sem_t f,e;

void *produce(void *arg)
{
    for(int i = 0; i < 10; i++)
    {
        sem_wait(&e);
        sem_wait(&mutex);
        printf("The produced item is %d\n",i);
        arr[(++a)%5]=i;
        sleep(1);
        sem_post(&mutex);
                sem_post(&f);
        printf("Full: %u\n",full);
    }
}
