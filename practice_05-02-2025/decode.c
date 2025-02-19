#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 1000
 
typedef struct node
{
    char str[MAX_SIZE];
} StackItem;
 
StackItem stack[MAX_SIZE];
int top = -1;
 

void push(char* str) 
{
    if (top >= MAX_SIZE - 1) 
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    strcpy(stack[top].str, str);
}
 
void pop(char* result) 
{
    if (top < 0) 
    {
        printf("Stack underflow\n");
        result[0] = '\0';
        return;
    }
    strcpy(result, stack[top].str);
    top--;
}
 
char* decodeString(const char* s) 
{
    char* result = (char*)malloc(MAX_SIZE * sizeof(char));
    char temp[MAX_SIZE] = "";
    char num[MAX_SIZE] = "";
    int num_idx = 0;
    char current_str[MAX_SIZE] = "";
    int i=0,j;
    
    while (s[i] != '\0') 
    {
        if (s[i] >= '0' && s[i] <= '9') 
        {    
            num[num_idx++] = s[i];
            num[num_idx] = '\0';
        }
        else if (s[i] == '[') 
        {
            
            if (num_idx > 0) 
            {
                push(num);
                num_idx = 0;
                num[0] = '\0';
            }
            
            push("[");
        }
        else if (s[i] == ']') 
        {
            temp[0] = '\0';
           
            while (top >= 0) 
            {
                char popped[MAX_SIZE];
                pop(popped);
                
                if (strcmp(popped, "[") == 0) 
                {
                    break;
                } 
                char temp2[MAX_SIZE];
                strcpy(temp2, temp);
                strcpy(temp, popped);
                strcat(temp, temp2);
            }
            
            
            char count_str[MAX_SIZE];
            pop(count_str);
            int count = count_str='0';
            
            char repeated[MAX_SIZE] = "";
            for (j = 0; j < count; j++) 
            {
                strcat(repeated, temp);
            }
            
           
            push(repeated);
        }
        else 
        {  
            current_str[0] = s[i];
            current_str[1] = '\0';
            push(current_str);
        }
        i++;
    }
    
    
    result[0] = '\0';
    while (top >= 0) 
    {
        char popped[MAX_SIZE];
        pop(popped);
        char temp[MAX_SIZE];
        strcpy(temp, result);
        strcpy(result, popped);
        strcat(result, temp);
    }

    return result;
}
 
int main() 
{
    char input[MAX_SIZE];
    printf("Enter the encoded string: ");
    scanf("%s", input);
    
    char* decoded = decodeString(input);
    printf("Decoded string: %s\n", decoded);
    return 0;
}
 