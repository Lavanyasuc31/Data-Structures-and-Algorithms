//Program to reverse a single linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int number;
    struct node *next;
};

struct node *temp=NULL, *prevnode=NULL, *currnode=NULL, *nextnode=NULL,*head=NULL,*tail=NULL;

void create()
{
    temp=(struct node*)malloc(sizeof(struct node));
    int number;
    printf("Enter the number:\t");
    scanf("%d",&number);
    temp->number=number;
    temp->next= NULL;
}

void insert()
{
    create();
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}

void display()
{
    temp=head;
    if(head==NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->number);
            temp=temp->next;
        }
    }
}

void reverse()
{
    currnode=head;
    nextnode=head;
    prevnode=NULL;
    while(currnode!=NULL)
    {
        nextnode=nextnode->next;
        currnode->next=prevnode;
        prevnode=currnode;
        currnode=nextnode;
    }
    head=prevnode;
}

int main()
{
    int n;
    printf("Enter the number of nodes:\t");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        insert();
    }
    printf("The linked list elements before reversing:\t");
    display();
    reverse();
    printf("\nThe linked list elements after reversing:\t");
    display();
    return 0;
}




