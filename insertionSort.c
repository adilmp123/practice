#include <stdio.h>
void readArray(int a[], int n)
{
    int i;
    printf("Enter elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void display(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void insertionSort(int a[],int n)
{
    int i,j,v;
    i=1;
    while(i<n)
    {
        v=a[i];
        j=i;
        while(a[j-1]>v && j>0)
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=v;
        i++;
    }
}
int main()
{
    int a[]={8,2,6,4,3,5};
    int n =6;
    insertionSort(a,n);
    display(a,n);
    
}
