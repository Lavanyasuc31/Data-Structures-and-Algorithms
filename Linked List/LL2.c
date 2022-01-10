/*Design, Develop and Implement a menu driven Program in C for the following operations on
Singly Linked List (SLL) of Student Data with the fields: USN, Name, Branch, Sem, PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of SLL
d. Perform Insertion and Deletion at Front of SLL
e. Demonstrate how this SLL can be used as STACK and QUEUE
f. Exit*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0;

struct node
{
    int sem, phno;
    char usn[20],name[20], branch[10];
    struct node *next;
};

struct node *head=NULL, *tail=NULL, *current;

void create()
{
    int sem,phno;
    char usn[20],name[20],branch[10];
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the name,usn, branch, sem, phno of the student");
    scanf("%s%s%s%d%d",name,usn,branch,&sem,&phno);
    strcpy(newnode->name,name);
    strcpy(newnode->usn,usn);
    strcpy(newnode->branch,branch);
    newnode->sem=sem;
    newnode->phno=phno;
    count++;
}

void insertatbeg()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        create();
        head=newnode;
        tail=newnode;
    }
    else
    {
        create();
        newnode->next=head;
        head=newnode;
    }
}


void insertatend()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        create();
        head=newnode;
        tail=newnode;
    }
    else
    {
        create();
        tail->next=newnode;
        tail=newnode;
    }
}


void display()
{
    current=head;
    if(current==NULL)
    {
        printf("Empty linked list\n");
        return;
    }
    else
    {
        printf("Linked list elements from the begining:\n");
        current=head;
        while(current!=NULL)
        {
            printf("%s%s%s%d%d\n",current->name,current->usn,current->branch,current->sem,current->phno);
            current=current->next;
        }
    }
    printf("Number of nodes=\t%d",count);
}

void deleteend()
{
    struct node *temp;
    temp=head;
    if(temp->next=NULL)
    {
        free(temp);
        head=NULL;
    }
    else
    {
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        printf("%s\t%s\t%s\t%d\t%d",tail->name,tail->usn,tail->branch,tail->sem,tail->phno);
        temp->next=NULL;
        free(tail);
        tail=temp;
    }
    count--;
}


void deletebeg()
{
    struct node *temp;
    temp=head;
    if(temp->next=NULL)
    {
        free(temp);
        head=NULL;
    }
    else
    {
        head=temp->next;
        printf("%s\t%s\t%s\t%d\t%d\n",temp->name,temp->usn,temp->branch,temp->sem,temp->phno);
        free(temp);
    }
    count--;
}

int main()
{
    int n,ch,i;
    printf("\n______Menu______\n");
    printf("1.Create an sll\n");
    printf("2.display the elements of sll\n");
    printf("3.insert at the end\n");
    printf("4.Delete at end\n");
    printf("5.Insert at front\n");
    printf("6.Delete at front\n");
    printf("7.Exit\n");
    printf("\n_______________\n");
    while(1)
    {
        printf("\nEnter your choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number of students:\t");
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                        insertatend();
                    break;
            case 2: display();
                    break;
            case 3 :insertatend();
                     break;
            case 4:deleteend();
                    break;
            case 5:insertatbeg();
                    break;
            case 6:deletebeg();
                    break;
            case 7: exit(1);
            default: printf("invalid choice\n");
        }
    }
}




