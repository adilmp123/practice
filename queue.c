#include <stdio.h>
#define MAX 100
int queue[MAX];
int front=-1,rear=-1;
int size;
void enqueue(int data)
{
    if(rear==size-1)
    {
        printf("\nqueue overflow");
    }
    else
    {
        if(front==-1)
        {
            front=0;
            queue[++rear]=data;
        }
        else
        {
            queue[++rear]=data;
        }
        printf("\n%d added",data);
    }
}
void dequeue()
{
    if(front==-1)
    {
        printf("\nQueue empty");
    }
    else
    {
        int del = queue[front];
        printf("\ndequeued %d",del);
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front++;
        }
    }
}
int main()
{
    size=5;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
}
