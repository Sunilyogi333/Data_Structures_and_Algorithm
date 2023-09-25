/*
Program to Evaluate a Postfix Expression
Note:
-To implement the operation corresponding to an operator symbol,we use a function oper() that accepts 
the character representation of an operator and two operands as input parameters, and returns the value
of the expression obtained by applying the operator to the two operands.
-The constant MAXCOLS is the maximum number of columns in a input line.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
void push(st *,double);
double pop(st *);
int empty(st *);
int idigit(char);
double oper(int, double, double);

void main()
{
    char expr[MAXCOLS];
    int position = 0;
    while((expr[position++]=getchar())!='\n')
    ;
    expr[--position]='\0';
    printf("%s%s","the original postfix expression is ",expr);

    printf("\n %f \n",eval(expr));
}

double eval(char expr[])
{
    int c, position;
    double opnd1,opnd2, value;
    st opndstk;

    opndstk.top=-1;
    for(position=0;(c=expr[position])!='\0';position)
    {
        if(idigit(c))
        {
            /*
            operand-- convert the charcter representation of the digit into double
            and push it onto the stack
            */
           push(&opndstk,(double)(c-'0'));
        }
        else
        {
            // operator
            opnd2 = pop(&opndstk);
            opnd1 = pop(&opndstk);
            value = oper(c,opnd1,opnd2);
            push(&opndstk,value);
        }
        return(pop(&opndstk));
    }
}
/*
 For completeness we present isdigit and oper.
 The function isdigit() simply checks its argument is a digit;
*/

int idigit(char c)
{
    if(c>='0'&&c<='9')
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
// int idigit(char symb)
// {
//     return (symb >= '0' && symb<= '9');
// }

/*
 This funciton is available as a predefined  macro is most C systems;
 The function oper() checks that its first argument is a valid operator and,
 if it is, determines the results of its opereation on the next two arguments.
 For exponenetiation, we use the function pow(op1, op2) as defined in math.h.
*/

double oper(int symb, double op1, double op2)
{
    switch ((symb))
    {
     case '+': return (op1 + op2);
     case '-': return (op1 - op2);
     case '*': return (op1 * op2);
     case '/': return (op1 / op2);
     case '$': return (pow(op1, op2));

     default:printf("%s", "illegal operation");
     exit(1);
    }
}
 void push(st *s, double x)
 {
     if(s->top == MAXCOLS-1)
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
     if(s->top == -1)
     {
         printf("%s", "stack underflow");
         exit(1);
     }
     else
     {
         return (s->items[(s->top)--]);
     }
 }

 
 