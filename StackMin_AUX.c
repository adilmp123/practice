#include <stdio.h>
#define MAX 100
int stack[MAX];
int tempStack[MAX];
int top=-1,tempTop=-1;
int size;
void tempPush(int data)
{
    tempStack[++tempTop]=data;
}
int tempPop()
{
    return tempStack[tempTop--];
}
void push(int data)
{
    if(top==size-1)
    {
        printf("\nstack overflow");
    }
    else
    {
        if(top==-1)
        {
            tempPush(data);
        }
        else
        {
            if(tempStack[tempTop]>data)
            {
                tempPush(data);
            }
        }
        stack[++top]=data;
        printf("\nadded %d",data);
    }
}
void pop()
{
    if(top==-1)
    {
        printf("\nstack empty");
    }
    else
    {
        if(tempStack[tempTop]==stack[top])
        {
            tempPop();
        }
        int del = stack[top--];
        printf("\npopped %d",del);
    }
}
void displayMin()
{
    printf("\nsmallest is %d ",tempStack[tempTop]);
}
int main()
{
    size=5;
    push(3);
    push(2);
    push(1);
    push(0);
    push(10);
    pop();
    pop();
    pop();
    displayMin();
}
