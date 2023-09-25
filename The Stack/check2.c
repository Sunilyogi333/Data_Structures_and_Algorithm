#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXCOLS 80
#define TRUE 1
#define FALSE 0

struct stack
{
    int top;
    double items[MAXCOLS];
};
typedef struct stack st;

double eval(char[]);
void push(st *, double);
double pop(st *);
int empty(st *);
int idigit(char);
double oper(char, double, double); // Change the parameter type to 'char'

int main() // Change from void main() to int main()
{
    char expr[MAXCOLS];
    int position = 0;
    while ((expr[position++] = getchar()) != '\n')
        ;
    expr[--position] = '\0';
    printf("%s%s", "the original postfix expression is ", expr);

    printf("\n %f \n", eval(expr));
    return 0; // Return 0 to indicate successful execution
}

double eval(char expr[])
{
    int c, position;
    double opnd1, opnd2, value;
    st opndstk;

    opndstk.top = -1;
    for (position = 0; (c = expr[position]) != '\0'; position++) // Fixed the loop
    {
        if (idigit(c))
        {
            push(&opndstk, (double)(c - '0'));
        }
        else
        {
            opnd2 = pop(&opndstk);
            opnd1 = pop(&opndstk);
            value = oper(c, opnd1, opnd2);
            push(&opndstk, value);
        }
    }
    return pop(&opndstk); // Moved the return statement here
}

int idigit(char c)
{
    return (c >= '0' && c <= '9');
}

double oper(char symb, double op1, double op2) // Change the parameter type to 'char'
{
    switch (symb) // Fixed the switch statement
    {
    case '+':
        return (op1 + op2);
    case '-':
        return (op1 - op2);
    case '*':
        return (op1 * op2);
    case '/':
        return (op1 / op2);
    case '^': // Use '^' for exponentiation
        return (pow(op1, op2));
    default:
        printf("%s", "illegal operation");
        exit(1);
    }
}

void push(st *s, double x)
{
    if (s->top == MAXCOLS - 1)
    {
        printf("%s", "stack overflow");
        exit(1);
    }
    else
    {
        s->items[++(s->top)] = x;
    }
}

double pop(st *s)
{
    if (s->top == -1)
    {
        printf("%s", "stack underflow");
        exit(1);
    }
    else
    {
        return (s->items[(s->top)--]);
    }
}