#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char item)
{
    if(top==MAX-1)
    {
        printf("stack overflow");
    }
    else
    {
        stack[++top]=item;
    }
}
char pop()
{
    return stack[top--];
}
void display()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%c",stack[i]);
    }
}
void postFixToInfix(char str[])
{
    int i;
    int len = strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/')
        {
            push(str[i]);
            push(' ');
        }
        else
        {
            int j;
            for(j=top-1;j>=0;j--)
            {
                if(stack[j]==' ')
                {
                    stack[j]=str[i];
                    break;
                }
            }
        }
    }
    display();
}
int main()
{
    // char str[50];
    // printf("Enter the postfix expression: ");
    // scanf("%s",str);
    
    // char str[]="ab+";
    char str[]="ab+cd+*";
    postFixToInfix(str);
}
