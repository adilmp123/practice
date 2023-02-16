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
void merge(int*,int,int,int);
void mergeSort(int a[],int lb, int ub)
{
    int mid;
    if(lb<ub)
    {
        mid = (lb+ub)/2;
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}

void merge(int a[],int lb, int mid, int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    int temp[100];
    while(i<=mid && j<=ub)
    {
        if(a[i]<=a[j])
        {
            temp[k]=a[i];
            i++;
        }
        else
        {
            temp[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        temp[k]=a[i];
        i++;
        k++;
    }   
    while(j<=ub)
    {
        temp[k]=a[j];
        j++;
        k++;
    }
    for(i=lb;i<=ub;i++)   
    {
        a[i]=temp[i];
    }
}
int main()
{
    int a[]={8,2,6,4,3,5};
    int n =6;
    mergeSort(a,0,n-1);
    display(a,n);
    
}
