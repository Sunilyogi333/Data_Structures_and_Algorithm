// Array Implementation of Linear Queue
#include <stdio.h>
#include<stdlib.h>
#define SIZE 20
struct queue
{
    int item[SIZE];
    int front;
    int rear;
};
typedef struct queue qt;
void insert(qt *q);
void display(qt *q);
void delete(qt *q);
int main()
{
    qt *q, s;
    q=&s;
    int ch;
    q->front = 0;
    q->rear = -1;
    printf("Menu in Program\n");
    printf("1.Insert \n2.Display \n3.Delete \n4.Exit");
    do
    {
        printf("\nEnter your choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(q);
            break;

        case 2:
            display(q);
            break;

        case 3:
            delete(q);
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
void insert(qt *q){
    int d;
    printf("Enter data to insert");
    scanf("%d",&d);
    if(q->rear == SIZE -1){
        printf("Queue is Full");
    }
    else{
        q->rear++;
        q->item[q->rear]=d;
    }
}
void display(qt *q){
    int i;
    if(q->rear<q->front){
        printf("Stack is Empty");
    }
    else{
        for(i=q->front; i<=q->rear; i++){
            printf("%d",q->item[i]);
        }
    }
}
void delete(qt *q){
    int d;
   if(q->rear<q->front){
        printf("Stack is Empty");
    }
    else{
        d=q->item[q->front];
         q->front++;
        printf("Deleted Element is %d",d);
    }
}
