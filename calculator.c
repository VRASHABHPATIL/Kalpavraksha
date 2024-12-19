#include<stdio.h>
#include<string.h>
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

void pushoprator(char operator1)
{
	otop = otop + 1;
	operator[otop] = operator1;
}

char popoprator()
{
    char operator1 = operator[otop];
    otop = otop - 1;
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

int precedence(char op)
{
	int result = 0;
	if(op=='*' || op=='/')
	{
		result = 2;
	}
	else if(op=='+' || op=='-')
	{
		result = 1;
	}
	return result;
}

int applyoperation(int a, int b, char op)
{
	int answer=0;
	switch(op)
	{
		case '+':
		{
			answer= a + b;
			break;
		}
		case '-':
		{
			answer= a - b;
			break;
		}
		case '*':
		{
			answer= a * b;
			break;
		}
		case '/':
		{
			if(b == 0)
			{
				printf("Division by zero error!");
				exit(1);
			}
			answer= a / b;
			break;
		}
	}
	return answer;
}

void evaluateExpression() 
{
	int operand2 = popvalue();
        int operand1 = popvalue();
        char operator = popoprator();
        pushvalue(applyoperation(operand1, operand2, operator));
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
                		evaluateExpression();
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
        	evaluateExpression();
    	}
    	int result = popvalue();
    	printf("Result: %d", result);
    	return 0;
}


    	

