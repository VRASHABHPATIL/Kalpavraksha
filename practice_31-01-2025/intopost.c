#include <stdio.h>
 
char operator[100];
int oflag = -1;
 
int isOperator(char a) {
    return (a == '^' || a == '/' || a == '*' || a == '%' || a == '+' || a == '-');
}
 
int precedence(char a) {
    if (a == '^' || a == '%') return 3;
    else if (a == '*' || a == '/') return 2;
    else return 1;
}
 
void pushoperator(char a) {
    operator[++oflag] = a;
}
 
void popoperator() {
    if (oflag == -1) {
        printf("Nothing to pop out\n");
    } else {
        printf("%c", operator[oflag--]);
    }
}
 
int main() {
    char str[100];
    int i;
 
    printf("Enter the infix expression: ");
    scanf("%[^\n]%*c", str);
 
    for (i = 0; str[i] != '\0'; i++) {
        if (isOperator(str[i])) {
            while (oflag != -1 && precedence(operator[oflag]) >= precedence(str[i])) {
                popoperator();
            }
            pushoperator(str[i]);
        } else {
            printf("%c", str[i]);
        }
    }
 
    while (oflag != -1) {
        popoperator();
    }
 
    return 0;
}
