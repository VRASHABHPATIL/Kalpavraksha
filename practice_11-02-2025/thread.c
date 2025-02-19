#include<pthread.h>
#include<stdio.h>
#include<stdio.h>
void* print(void *a)
{
    int *num=(int*)a;
    printf("%d\n",*num);
}
int main()
{
    pthread_t thread1;
    int num=20;
    pthread_create(&thread1,NULL,print,(void*)&num);
    pthread_join(thread1,NULL);
    return 0;
}