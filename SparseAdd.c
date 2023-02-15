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

void sparseAdd(sparse a[], sparse b[], sparse c[])
{
    if (a[0].row != b[0].row || a[0].col != b[0].col)
    {
        printf("cant add");
        return;
    }
    c[0].row = a[0].row;
    c[0].col = a[0].col;
    int i = 1, j = 1, k = 1;
    while (i <= a[0].val && j <= b[0].val)
    {
        if (a[i].row > b[j].row || a[i].row == b[j].row && a[i].col > b[j].col)
        {
            c[k].row = b[j].row;
            c[k].col = b[j].col;
            c[k].val = b[j].val;
            j++;
            k++;
        }
        else if (a[i].row < b[j].row || a[i].row == b[j].row && a[i].col < b[j].col)
        {
            c[k].row = a[i].row;
            c[k].col = a[i].col;
            c[k].val = a[i].val;
            i++;
            k++;
        }
        else if (a[i].row == b[j].row && a[i].col == b[j].col)
        {
            c[k].row = a[i].row;
            c[k].col = a[i].col;
            c[k].val = a[i].val + b[j].val;
            i++;
            j++;
            k++;
        }
    }
    while (i <= a[0].val)
    {
        c[k].row = a[i].row;
        c[k].col = a[i].col;
        c[k].val = a[i].val;
        i++;
        k++;
    }
    while (j <= b[0].val)
    {
        c[k].row = b[j].row;
        c[k].col = b[j].col;
        c[k].val = b[j].val;
        j++;
        k++;
    }
    c[0].val=k-1;
}
int main()
{
    sparse a[100],b[100],c[200];
    system("clear");
    readSparse(a);
    display(a);
    printf("\n");
    readSparse(b);
    display(b);
    printf("\n");
    sparseAdd(a,b,c);
    printf("sum is\n");
    display(c);

}
