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
void Transpose(sparse a[],sparse b[])
{
    b[0].col=a[0].row;
    b[0].row=a[0].col;
    b[0].val=a[0].val;
    int i=1,j=1,k=1;
    for(i=0;i<a[0].col;i++)
    {
        for(j=1;j<=a[0].val;j++)
        {
            if(a[j].col==i)
            {
                b[k].row=a[j].col;
                b[k].col=a[j].row;
                b[k].val=a[j].val;
                k++;
            }
        }
    }

}
int main()
{
    sparse a[100],b[100];
    system("clear");
    readSparse(a);
    display(a);
    printf("\n");
    Transpose(a,b);
    display(b);
}
