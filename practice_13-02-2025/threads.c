#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock1;
int shared=1000;
void* print(void* val)
{
    int a=*(int*)val;
    printf("called by thread\n");
   // printf("%d\n",a);
    return val;
}

void * incriment()
{
    pthread_mutex_lock(&lock1);
    shared=shared+10;
    pthread_mutex_unlock(&lock1);
}
void* decrement()
{
    pthread_mutex_lock(&lock1);
    shared=shared-10;
    pthread_mutex_unlock(&lock1);
}
int main()
{
    pthread_mutex_init(&lock1,NULL);
    int i;
    pthread_t thread[10];
    // int n=10;
    // for(i=0;i<2;i++)
    // {
    //     pthread_create(&thread,NULL,print,(void*)&n);
    //     void* result;
    //     pthread_join(thread,&result);
    //     int a=*((int*)result);
    //     printf("%d\n",a);

    // }
    pthread_create(&thread[0],NULL,incriment,NULL);
    pthread_create(&thread[1],NULL,decrement,NULL);
    pthread_create(&thread[2],NULL,incriment,NULL);
    pthread_create(&thread[3],NULL,decrement,NULL);
    pthread_create(&thread[4],NULL,incriment,NULL);
    pthread_create(&thread[5],NULL,decrement,NULL);
    pthread_create(&thread[6],NULL,incriment,NULL);
    pthread_create(&thread[7],NULL,decrement,NULL);
    pthread_create(&thread[8],NULL,incriment,NULL);
    pthread_create(&thread[9],NULL,decrement,NULL);

    pthread_join(thread[0],NULL);
    pthread_join(thread[1],NULL);
    pthread_join(thread[2],NULL);
    pthread_join(thread[3],NULL);
    pthread_join(thread[4],NULL);
    pthread_join(thread[5],NULL);
    pthread_join(thread[6],NULL);
    pthread_join(thread[7],NULL);
    pthread_join(thread[8],NULL);
    //pthread_join(thread[9],NULL);
    
   // pthread_mutex_destroy(&lock1);

    printf("%d\n",shared);
    return 0;

}