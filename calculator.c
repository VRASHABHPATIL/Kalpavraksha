#include<stdio.h>
#include<string.h>
#define max 500

void pushvalue(int* valueStack, int* valueTop, int value)
{
    *valueTop = *valueTop + 1;
    valueStack[*valueTop] = value;
}

int popvalue(int* valueStack, int* valueTop)
{
    int value = valueStack[*valueTop];
    *valueTop = *valueTop - 1;
    return value;
}

void pushoprator(char* operatorStack, int* operatorTop, char operator1)
{
    *operatorTop = *operatorTop + 1;
    operatorStack[*operatorTop] = operator1;
}

char popoprator(char* operatorStack, int* operatorTop)
{
    char operator1 = operatorStack[*operatorTop];
    *operatorTop = *operatorTop - 1;
    return operator1;
}

int isDigit(char c)
{
    int result = 0;
    if(c>='0' && c<='9')
    {
        result=1;
    }
    return result;
}

int isoperator(char c)
{
    int result =0;
    if(c=='+' || c=='-' || c=='*' || c=='/')
    {
        result= 1;
    }
    return result;
}

int precedence(char operator)
{
    int result = 0;
    if(operator=='*' || operator=='/')
    {
        result = 2;
    }
    else if(operator=='+' || operator=='-')
    {
        result = 1;
    }
    return result;
}

int applyoperation(int operand1, int operand2, char operator)
{
    int answer=0;
    switch(operator)
    {
        case '+':
        {
            answer= operand1 + operand2;
            break;
        }
        case '-':
        {
            answer= operand1 - operand2;
            break;
        }
        case '*':
        {
            answer= operand1 * operand2;
            break;
        }
        case '/':
        {
            if(operand2 == 0)
            {
                printf("Division by zero error!");
                exit(1);
            }
            answer= operand1 / operand2;
            break;
        }
    }
    return answer;
}

void evaluateExpression(int* valueStack, int* valueTop, char* operatorStack, int* operatorTop) 
{
    int operand2 = popvalue(valueStack, valueTop);
    int operand1 = popvalue(valueStack, valueTop);
    char operator = popoprator(operatorStack, operatorTop);
    pushvalue(valueStack, valueTop, applyoperation(operand1, operand2, operator));
}

int main() 
{
    char expression[max];
    // Local variables instead of global
    int valueStack[max];
    char operatorStack[max];
    int valueTop = -1;
    int operatorTop = -1;

    printf("Enter a mathematical expression: ");
    fgets(expression, sizeof(expression), stdin);
    int length = strlen(expression);
    if (length>0 && expression[length-1]=='\n')
    {
        expression[length-1] = '\0';
    }
    
    int i = 0;
    while (expression[i]!='\0') 
    {
        if (expression[i] == ' ') 
        {
            i++;
            continue;
        }
        if (isDigit(expression[i]))
        {
            int value = 0;
            
            while (expression[i] != '\0' && isDigit(expression[i])) 
            {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            pushvalue(valueStack, &valueTop, value);
            i--; 
        }
        else if (isoperator(expression[i])) 
        {
            while (operatorTop != -1 && precedence(operatorStack[operatorTop]) >= precedence(expression[i])) 
            {
                evaluateExpression(valueStack, &valueTop, operatorStack, &operatorTop);
            }
            pushoprator(operatorStack, &operatorTop, expression[i]);
        }
        else 
        {
            printf("Invalid expression");
            exit(1);
        }
        i++;
    }
    while (operatorTop != -1) 
    {
        evaluateExpression(valueStack, &valueTop, operatorStack, &operatorTop);
    }
    int result = popvalue(valueStack, &valueTop);
    printf("Result: %d", result);
    return 0;
}
