//Operations on a double linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int ssn, phno;
    float sal;
    char name[20], dept[20], design[20];
    struct node *prev, *next;
};

struct node *head=NULL, *tail=NULL,*temp,*temp1;

void create()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the ssn, name, designation, department, salary and phone number of the employee\t");
    scanf("%d%s%s%s%f%d",&temp->ssn,temp->name,temp->design,temp->dept,&temp->sal,&temp->phno);
    temp->prev=NULL;
    temp->next=NULL;
}

void insert_beg()
{
    create();
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}

void insert_end()
{
    create();
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
    }
}

void delete_beg()
{
    temp=head;
    if(temp->next==NULL)
    {
         printf("%d\t%s\t%s\t%s\t%f\t%d\n",temp->ssn,temp->name,temp->design,temp->dept,temp->sal,temp->phno);
        free(temp);
        head=NULL;
    }
    else
    {
        temp1=head;
        printf("%d\t%s\t%s\t%s\t%f\t%d\n",temp1->ssn,temp1->name,temp1->design,temp1->dept,temp1->sal,temp1->phno);
        head=head->next;
        head->prev=NULL;
        temp1->next=NULL;
        free(temp1);
    }
}


void delete_end()
{
    temp1=tail;
    temp=head;
    if(temp->next==NULL)
    {
         printf("%d\t%s\t%s\t%s\t%f\t%d\n",temp->ssn,temp->name,temp->design,temp->dept,temp->sal,temp->phno);
        free(temp);
        head=NULL;
    }
    else
    {
        printf("%d\t%s\t%s\t%s\t%f\t%d\n",temp1->ssn,temp1->name,temp1->design,temp1->dept,temp1->sal,temp1->phno);
        tail=temp1->prev;
        tail->next=NULL;
        temp1->prev=NULL;
    }
}

void display()
{
    if(head==NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        temp1=head;
        while(temp1!=NULL)
        {
           printf("%d\t%s\t%s\t%s\t%f\t%d\n",temp1->ssn,temp1->name,temp1->design,temp1->dept,temp1->sal,temp1->phno);
           temp1=temp1->next;
        }
    }
}

int main()
{
    int n,i,choice;
    while(1)
    {
        printf("Menu\n");
        printf("1.Create a  linked list\n 2.Insert in the beginning\n 3.Delete in the beginning\n 4.Insert at the end\n 5.Delete at the end\n 6.Display\n 7.exit\n");
        printf("enter your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the number of nodes:\t");
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                    {
                        insert_end();
                    }
                    break;
            case 2: insert_beg();
                    break;
            case 3: delete_beg();
                    break;
            case 4: insert_end();
                    break;
            case 5: delete_end();
                    break;
            case 6: display();
                    break;
            case 7: exit(1);
        }
    }
    return 0;
}
