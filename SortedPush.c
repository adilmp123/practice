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
    else if(top==-1)
    {
        stack[++top]=data;
    }
    else
    {
        while(stack[top]>data)
        {
            tempPush(pop());
        }
        stack[++top]=data;
        while(tempTop!=-1)
        {
            push(tempPop());
        }
        printf("\nadded %d",data);
    }
}
int pop()
{
    if(top==-1)
    {
        printf("\nstack empty");
    }
    else
    {
        return stack[top--];
    }
}
void display()
{
    int i;
    printf("\n");
    for(i=0;i<=top;i++)
    {
        printf("%d ",stack[i]);
    }
}
int main()
{
    size=6;
    push(3);
    push(2);
    push(1);
    push(0);
    push(10);
    push(7);
    display();
}
