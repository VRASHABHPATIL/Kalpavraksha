#include <stdio.h>
 
#define MAX 100
 
int checkBracketType(char c) 
{
    if (c == '(' || c == '[' || c == '{') 
    {
        return 0;
    } 
    else 
    {
        return 1;
    }
}
 
void push(char stack[], int *top, char value) 
{
    if (*top < MAX - 1) 
    {
        (*top)++;
        stack[*top] = value;
    }
}
 
char pop(char stack[],int *top) 
{
    if (*top >= 0) 
    {
        char temp = stack[*top];
        (*top)--;
        return temp;
    }
    return 0;
}
 
int isMatchingPair(char open, char close) 
{
    int flag=0;
    if((open == '(' && close == ')') ||(open == '{' && close == '}') ||(open == '[' && close == ']'))
    {
        flag=1;
    }
    return flag;
    
}
 
int main() {
    char input[MAX], stack[MAX];
    int iterator, top = -1;
    int balancingFlag = 0;
    int *top_pointer = &top;
 
    printf("Enter the input: ");
    scanf("%[^\n]%*c", input);
 
    for (iterator = 0; input[iterator] != '\0'; iterator++) 
    {
        char current = input[iterator];
 
        if (!checkBracketType(current)) 
        {
            push(stack, top_pointer, current);
        } 
        else 
        {
            if (top == -1) 
            {
                balancingFlag = 1;
                break;
            }
            char topChar = pop(stack,top_pointer);
            if (!isMatchingPair(topChar, current)) 
            {
                balancingFlag = 1;
                break;
            }
        }
    }
 
    if (top == -1 && balancingFlag == 0) 
    {
        printf("Balanced\n");
    } 
    else 
    {
        printf("Not Balanced\n");
    }
 
    return 0;
}