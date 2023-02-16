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
void buildHeap(int*,int);
void heapSort(int*,int);
void heapify(int*,int,int);

void heapSort(int a[],int n)
{
    buildHeap(a,n);
    int i;
    for(i=n-1;i>=0;i--)
    {
        swap(a,a+i);
        heapify(a,i,0);
    }
}
void buildHeap(int a[],int n)
{
    int i;
    for(i=(n/2)-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
}
void heapify(int a[],int n, int i)
{
    int largest=i;
    int L = 2*i+1;
    int R = 2*i+2;
    if(L<n && a[L]>a[largest])
    {
        largest=L;
    }
    if(R<n && a[R]>a[largest])
    {
        largest=R;
    }
    if(largest!=i)
    {
        swap(a+largest,a+i);
        heapify(a,n,i);
    }
}
int main()
{
    int a[]={8,2,6,4,3,5};
    int n =6;
    heapSort(a,n);
    display(a,n);
    
}
