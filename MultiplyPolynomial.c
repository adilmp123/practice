#include <stdio.h>
#include <stdlib.h>
struct node
{
    int exp;
    int coeff;
    struct node * next;
};

struct node * createNode(int coeff, int exp)
{
    struct node * new =  (struct node *)malloc(sizeof(struct node));
    new->coeff =coeff;
    new->exp = exp;
    new->next=NULL;
    return new;
}
void add(struct node ** poly,int coeff,int exp)
{
    struct node * ptr = *poly;
    struct node * new = createNode(coeff,exp);
    if((*poly)==NULL)
    {
        (*poly)=new;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new;
    }
}
void readPoly(struct node ** poly)
{
    int n,i,coeff,exp;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(i=0;i<3;i++)
    {
        scanf("%d",&coeff);
        scanf("%d",&exp);
        add(poly,coeff,exp);
    }
}
void display(struct node **poly)
{
    if(!(*poly))
    {
        return NULL;
    }
    struct node * ptr = *poly;
    while(ptr!=NULL)
    {
        printf("%dx^%d",ptr->coeff,ptr->exp);
        if(ptr->next!=NULL)
        {
            printf(" + ");
        }
        ptr=ptr->next;
    }
}
struct node * isRepeat(struct node **poly,int exp)
{
    struct node * ptr = *poly;
    while(ptr!=NULL)
    {
        if(ptr->exp==exp)
        {
            return ptr;
        }
        ptr=ptr->next;
    }
    return NULL;
}
void multiply(struct node **poly1, struct node **poly2, struct node **poly3)
{
    struct node * ptr1 = (*poly1);
    struct node * ptr2;
    while(ptr1!=NULL)
    {
        ptr2 = (*poly2);
        while(ptr2!=NULL)
        {
            if(isRepeat(poly3,ptr1->exp+ptr2->exp)==NULL)
            {
                add(poly3,ptr1->coeff*ptr2->coeff,ptr1->exp+ptr2->exp);
            }
            else
            {
                isRepeat(poly3,ptr1->exp+ptr2->exp)->coeff+=ptr1->coeff*ptr2->coeff;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }

}
int main()
{
    struct node * head1 = NULL;
    struct node * head2 = NULL;
    struct node * head3 = NULL;
    system("clear");
    readPoly(&head1);
    readPoly(&head2);
    multiply(&head1,&head2,&head3);
    display(&head3);
}
