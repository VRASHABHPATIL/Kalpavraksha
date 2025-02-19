#include<pthread.h>
#include<stdio.h>
#include<stdio.h>
void* print(void *a)
{
    int *num=(int*)a;
    //printf("%d\n",*num);
    //return num;
    pthread_exit(num);
}
int main()
{
    pthread_t thread1;
    int num=20;
    void *result;
    pthread_create(&thread1,NULL,print,(void*)&num);
    pthread_join(thread1,&result);
    int *r1=(int*)result;
    printf("%d\n",*r1);
    return 0;
}