#include <stdio.h>
typedef struct
{
    int row;
    int col;
    int val;
} sparse;

void readSparse(sparse a[])
{
    int size;
    printf("Enter the number of rows of representation: ");
    scanf("%d", &size);
    printf("Enter representation\n");
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i].row);
        scanf("%d", &a[i].col);
        scanf("%d", &a[i].val);
    }
}
void display(sparse a[])
{
    int i;
    for (i = 0; i <= a[0].val; i++)
    {
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].val);
    }
}
int symmetric(sparse a[])
{
    int i,j;
    for(i=0;i<=a[0].val;i++)
    {
        for(j=i+1;j<=a[0].val;j++)
        {
            if(a[i].row==a[j].col && a[i].col==a[j].row)
            {
                if(a[i].val!=a[j].val)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}
int main()
{
    sparse a[100],b[100];
    system("clear");
    readSparse(a);
    if(symmetric(a))
    {
        printf("symmetric");
    }
    else
    {
        printf("npt symmetric");
    }
}
