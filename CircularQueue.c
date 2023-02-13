#include <stdio.h>
#define MAX 100
int queue[MAX];
int front=-1,rear=-1;
int size;
void enqueue(int data)
{
    if(front==-1)
    {
        front=rear=0;
        queue[rear]=data;
        printf("\n%d added",data);
    }
    else
    {
        int md = (rear+1)%size;
        if(md!=front)
        {
            rear=md;
            queue[rear]=data;
            printf("\n%d added",data);
        }
        else
        {
            printf("\nQueue overflow");
        }
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
            front = (front+1)%size;
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
    enqueue(1);
    enqueue(2);
    dequeue();
    dequeue();
    enqueue(1);
    enqueue(2);
    dequeue();
    dequeue();
    enqueue(1);
    enqueue(2);
}
