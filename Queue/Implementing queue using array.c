//Implementing queues using array

#include<stdio.h>
#include<stdlib.h>
int  q[10],f=0,r=-1;
void push_ele()
{
    int ele;
    if(r==9)
    {
        printf("The queue is completely filled\n");
    }
    else
    {
        printf("\nEnter the element to be inserted:\t");
        scanf("%d",&ele);
        q[++r]=ele;
    }
}

void pop_ele()
{
    if(r==-1!!f==r+1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nThe popped out element is:\t%d",q[f]);
        f++;
    }
}

void display()
{
    printf("\nThe queue elements:\n");
    for(int i=f;i<=r;i++)
    {
        printf("\n%d\t",q[f]);
    }
}

int main()
{
    int  n,ch;
    while(1)
    {
        printf("\n1.Create a queue\n2.Enqueue\n3.Dequeue\n4.Display\n5.Quit\n");
        printf("Enter the choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter the number of elements to be inserted:\t");
                    scanf("%d",&n);
                    for(int i=0;i<n;i++)
                        push_ele();
                    break;
            case 2: push_ele();
                    break;
            case 3: pop_ele();
                    break;
            case 4: display();
                    break;
            case 5: exit(1);

        }
    }
    return 0;
}
