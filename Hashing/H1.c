//Linear probing in hash table

#include<stdio.h>
#include<stdlib.h>
#define max 100

int create(int);
void linear_prob(int[],int,int);
void display(int[]);

int main()
{
    int a[max],num,key,i;
    int ans=1;
    printf("Collission handling by linear probing\n");
    for(i=0;i<max;i++)
    {
        a[i]=-1;
    }
    do
    {
        printf("Enter the data\n");
        scanf("%4d",&num);
        key=create(num);
        linear_prob(a,key,num);
        printf("Do you wish to continue?(1/0)");
        scanf("%d",&ans);
    }while(ans);
    display(a);
    return 0;
}

int create(int num)
{
    int key;
    key=num%100;
    return key;
}

void linear_prob(int a[max],int key, int num)
{
    int flag, i,count=0;
    flag=0;
    if(a[key]==-1)
    {
        a[key]=num;
    }
    else
    {
        printf("Collission detected....!!!!\n");
        i=0;
        while(i<max)
        {
            if(a[i]!=-1)
                count++;
            i++;
        }
        printf("Collission avoided  successfully using linear probing\n");
        if(count==max)
        {
            printf("\nHash table is full\n");
            display(a);
            exit(1);
        }
        for(i=key+1;i<max;i++)

            if(a[i]==-1)
            {
                a[i]=num;
                flag=1;
                break;
            }
        i=0;
        while((i<key)&&(flag==0))
        {
            if(a[i]==-1)
            {
                a[i]=num;
                flag=1;
                break;
            }
            i++;
        }
    }

}

void display(int a[max])
{
    int i,choice;
    printf("\n 1.Display all\n 2.Filtered display\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("the hash table is\n");
        for(i=0;i<max;i++)
            printf("\n%d\t%d\n",i,a[i]);
    }
    else
    {
        printf("The hash table is :\n");
        for(i=0;i<max;i++)
        {
            if(a[i]!=-1)
            {
                printf("\n%d\t%d\n",i,a[i]);
                continue;
            }
        }
    }
}
