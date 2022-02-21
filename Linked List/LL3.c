//Program to search an element in the list

#include<stdio.h>
#include<stdlib.h>
 struct node
 {
     int n;
     struct node *next;
 };
 struct node *head=NULL, *tail=NULL,*temp1=NULL,*temp=NULL;

 void create()
 {
     int n;
     temp=(struct node*)malloc(sizeof(struct node));
     printf("Enter the number\n");
     scanf("%d",&n);
     temp->n=n;
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

 int main()
 {
     int k,key,flag=0;
     printf("Enter the number of nodes:\t");
     scanf("%d",&k);
     for(int i=0;i<k;i++)
     {
         insert();
     }
     printf("Enter the key:\t");
     scanf("%d",&key);
     temp1=head;
     while(temp1!=NULL)
     {
         if(temp1->n==key)
         {
             flag=1;
             break;
         }
         else
         {
            temp1=temp1->next;
         }
     }
     if(flag==1)
     {
         printf("Key is found\n");
     }
     else
     {
         printf("Key is not found\n");
     }
     return 0;
 }
