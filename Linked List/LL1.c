//Program to create a single linked list and display it's elements

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node* next;
};

struct node *head=NULL, *tail=NULL;

void createnode(int info)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=info;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }
}



void display()
{
    if(head==NULL)
    {
        printf("Empty linked list\n");
        return ;
    }
    else
    {
        printf("Linked list elements from the beginning:\n");
        struct node *current;
        current=head;
        while(current!=NULL)
        {
            printf("%d\t",current->info);
            current=current->next;
        }
    }
}


int main()
{
    int info,n;
    printf("Enter the number of nodes:\t");
    scanf("%d",&n);
    for( int i=1;i<=n;i++)
    {
        printf("Enter the information for %d  node:\t",i);
        scanf("%d",&info);
        createnode(info);
    }
    display();
    return 0;
}
