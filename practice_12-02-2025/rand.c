#include <stdio.h>
#include <stdlib.h>
int main()
{
    
    //int N = 1000;

    
    for (int i = 0; i < 10; i++) {
        
    
        int value = 125- rand() % (165);
        
        printf("%d \t", value);
        
    }
    printf("\n");

    return 0;
}