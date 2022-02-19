//Program to concatenate two strings

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int number;
    struct node* next;
};

struct node *temp=NULL,*head1=NULL,*head2=NULL,*tail1=NULL,*tail2=NULL,*temp1=NULL;

void create()
{
    int number;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the number:\t");
    scanf("%d",&number);
    temp->number=number;
    temp->next=NULL;
}

void list1()
{
    create();
    if(head1==NULL)
    {
        head1=temp;
        tail1=temp;
    }
    else
    {
        tail1->next=temp;
        tail1=temp;
    }
}


void list2()
{
    create();
    if(head2==NULL)
    {
        head2=temp;
        tail2=temp;
    }
    else
    {
        tail2->next=temp;
        tail2=temp;
    }
}


void concatenate()
{
     tail1->next=head2;
     tail1=tail2;
     head2=NULL;
     tail2=NULL;
}

void display()
{
    temp1=head1;
    if(temp1==NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        printf("Linked list elements:\t");
        while(temp1!=NULL)
        {
            printf("%d\t",temp1->number);
            temp1=temp1->next;
        }
    }
}

int main()
{
    int n1,n2;
    printf("Enter the number of nodes in first list\t");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
    {
        list1();
    }
    printf("Enter the number of nodes in the second list:\t");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
    {
        list2();
    }
    concatenate();
    display();
    return 0;
}


