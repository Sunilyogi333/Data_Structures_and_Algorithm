#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct stack
{
    int top;
    int item[SIZE];
};
typedef struct stack st;
void push(st *s, int);
void pop(st *s);
void display(st *s);

int main()
{
    int element, choice;
    st *s, t;
    s = &t;
    s->top = -1;
    do
    {
        printf("Menu in program\n");
        printf("1.Push the element\n");
        printf("2.Pop the element\n");
        printf("3.Display the elements\n");
        printf("4.Exit\n");

        printf("Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element\n");
            scanf("%d", &element);
            push(s, element);
            break;

        case 2:
            pop(s);
            break;

        case 3:
            display(s);
            break;

        case 4:
            exit(1);
            break;

        default: printf("Invalid choice \n");
        }
    } while (choice != 0);
    return 0;
}
void push(st *s, int d)
{
    if (s->top == SIZE - 1)
    {
        printf("Stack is full ");
    }
    else
    {
        s->top++;
        s->item[s->top] = d;
    }
}
void pop(st *s)
{
    if (s->top == -1)
    {
        printf("stack is empty \n");
    }

    else
    {
        printf("Deleted item is %d\n", s->item[s->top--]);
    }
}
void display(st *s)
{
    int i;
    if (s->top == -1)
    {
        printf("stack is empty \n");
    }
    else
    {
        printf("The elements in stack are \n");
        for (i = s->top; i >= 0; i--)
        {
            printf("%d\n", s->item[i]);
        }
    }
}
