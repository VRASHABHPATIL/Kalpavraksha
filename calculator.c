#include<stdio.h>
#include<string.h>
#include<stdlib.h> //used this beacouse i have used the exit() finction 
#define max 500
int oprand[max], vtop = -1, otop = -1; 
char operator[max]; 

// The above global variable can be modified or accessed by any function in the program

void pushvalue(int value)
{
	vtop = vtop + 1;
	oprand[vtop] = value;
}

int popvalue()
{
    int value = oprand[vtop];
    vtop = vtop - 1;
    return value;
}

void pushoprator(char op)
{
	otop = otop + 1;
	operator[otop] = op;
}

char popoprator()
{
    char op = operator[otop];
    otop = otop - 1;
    return op;
}

int isDigit(char c)
{
	if(c>='0' && c<='9')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isoperator(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/')
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int precedence(char op)
{
	if(op=='*' || op=='/')
	{
		return 2;
	}
	else if(op=='+' || op=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int applyoperation(int a, int b, char op)
{
	switch(op)
	{
		case '+':
		{
			return a + b;
		}
		case '-':
		{
			return a - b;
		}
		case '*':
		{
			return a * b;
		}
		case '/':
		{
			if(b == 0)
			{
				printf("Division by zero error!");
				exit(1);
			}
			return a / b;
		}
	}
	return 0;
}

void evaluatetop() 
{
	int b = popvalue();
        int a = popvalue();
        char op = popoprator();
        pushvalue(applyoperation(a, b, op));
}

int main() 
{
	char expression[max];
    	printf("Enter a mathematical expression: ");
    	fgets(expression, sizeof(expression), stdin);
    	int len = strlen(expression);
    	if (len>0 && expression[len-1]=='\n')
    	{
        	expression[len-1] = '\0';
    	}
    	
	int i = 0;
        while (expression[i]!='\0') 
        {
        	if (expression[i] == ' ') 
        	{
                	i++;
            
        	}
        	if (isDigit(expression[i]))
        	{
                	int value = 0;
            
                 	while (expression[i] != '\0' && isDigit(expression[i])) 
                 	{
                		value = value * 10 + (expression[i] - '0');
                		i++;
            		}
            		pushvalue(value);
            		i--; 
        	}
        	else if (isoperator(expression[i])) 
        	{
            		while (otop!= -1 && precedence(operator[otop]) >= precedence(expression[i])) 
            		{
                		evaluatetop();
            		}
            		pushoprator(expression[i]);
        	}
        	else 
        	{
            		printf("Invalid expression");
            		exit(1);
        	}
        	i++;
   	 }
    	while (otop!= -1) 
    	{
        	evaluatetop();
    	}
    	int result = popvalue();
    	printf("Result: %d", result);
    	return 0;
}


    	

