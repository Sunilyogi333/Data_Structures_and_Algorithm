#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

struct stack
{
    int item[SIZE];
    int top;
};
typedef struct stack st;
void createemptystack(st *s);
void push(st *s);
void pop(st *s);
void display(st *s);

int main()
{
    int ch;
    st *s,k;
    s=&k;
    createemptystack(s);
    printf("Menu in Program\n");
    printf("1.Push the Element\n");
    printf("2.Pop the Element\n");
    printf("3.Display the Elements\n");
    printf("4.Exit");

    do
    {
        printf("\nEnter your choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push(s);
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

        default:
            printf("Invalid choice");
        }
    } while (ch < 5);
    return 0;
}
void createemptystack(st *s)
{
    s->top =-1;
}
void push(st *s)
{
    int d;
    printf("Enter data to be inserted");
    scanf("%d",&d);
    if (s->top == SIZE - 1)
    {
        printf("Stack is full");
    }
    else
    {
        s->top++;
        s->item[s->top] = d;
    }
}
void pop(st *s)
{
    int d;
    if (s->top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        d = s->item[s->top];
        s->top--;
        s->item[s->top] = d;
        printf("Deleted item is %d", s->item[s->top]);
    }
}
void display(st *s)
{
    int i;
    if (s->top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        for (i = s->top; i >= 0; i--)
        {
            printf("%d", s->item[i]);
        }
    }
}