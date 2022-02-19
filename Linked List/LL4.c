//Program to delete the node at specified location


#include<stdio.h>
#include<stdlib.h>


struct node
{
    int number;
    struct node* next;
};

struct node *temp=NULL,*head=NULL,*tail=NULL,*temp1=NULL,*temp2=NULL;

void create()
{
    int number;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the number\n");
    scanf("%d",&number);
    temp->number=number;
    temp->next=NULL;
}


void insert()
{
    if(head==NULL)
    {
        create();
        head=temp;
        tail=temp;
    }
    else
    {
        create();
        tail->next=temp;
        tail=temp;
    }
}


void delete_ele(int pos,int n)
{
    temp1=head;
    if(pos==1)
    {
        if(temp1->next==NULL)
        {
            printf("The deleted element is %d",temp1->number);
            free(temp1);
            head=NULL;
        }
        else
        {
            printf("The deleted element is %d",temp1->number);
            head=temp1->next;
            free(temp1);
        }
    }
    else if(pos==n)
    {
        while(temp1->next!=tail)
        {
            temp1=temp1->next;
        }
        printf("The deleted element is %d",tail->number);
        free(tail);
        temp1->next=NULL;
        tail=temp1;
    }
    else
    {
        int i=1;
        while(i<pos-1)
        {
            temp1=temp1->next;
            i++;
        }
        temp2=temp1->next;
        temp->next=temp2->next;
         printf("The deleted element is %d",temp2->number);
        free(temp2);
    }
}

int main()
{
    int n,pos;
    printf("enter the number of nodes");
    scanf("%d",&n);
    for(int i=1;i<n+1;i++)
    {
        insert();
    }
    printf("Enter the position where the element is to be deleted:\t");
    scanf("%d",&pos);
    delete_ele(pos,n);
    return 0;
}







