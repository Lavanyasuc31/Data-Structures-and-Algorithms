//Evaluation and addition of two polynomials

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int coef, x, y, z;
    struct node *next;
};
typedef struct node* NODE;

NODE create()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    return x;
}

NODE readpoly()
{
    NODE temp, curr, head;
    char ch;
    head=create();
    head->coef=-1;
    head->x=-1;
    head->y=-1;
    head->z=-1;
    head->next=head;
    do
    {
        temp=create();
        printf("Enter the coeffitient and powers of x, y and z:\t");
        scanf("%d%d%d%d",&temp->coef,&temp->x,&temp->y,&temp->z);
        curr=head;
        while(curr->next!=head)
        {
            curr=curr->next;
        }
        curr->next=temp;
        temp->next=head;
        printf("Do you want to continue?(y/n)");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    return head;
}

int compare(NODE a, NODE b)
{
    if(a->x > b->x)
        return 1;
    else if( a->x < b->x)
        return -1;
    else if(a->y > b->y)
        return 1;
    else if(a->y < b->y)
        return -1;
    else if(a->z > b->z)
        return 1;
    else if(a->z < b->z)
        return -1;
    return 0;
}

void attach(int cf, int x1,int y1, int z1, NODE *ptr)
{
    NODE temp;
    temp=create();
    temp->coef=cf;
    temp->x=x1;
    temp->y=y1;
    temp->z=z1;
    (*ptr)->next=temp;
    *ptr=temp;
}

NODE addpoly(NODE a,NODE b)
{
    NODE starta , lastc, c;
    int sum, flag=0;
    starta=a;
    a=a->next;
    b=b->next;
    c=create();
    c->coef=-1;
    c->x=-1;
    c->y=-1;
    c->z=-1;
    lastc=c;
    do
    {
        switch(compare(a,b))
        {
            case -1: attach(b->coef,b->x,b->y,b->z,&lastc);
                     b=b->next;
                     break;
            case 0: if(starta==a) flag=1;
                    else
                    {
                        sum=a->coef+b->coef;
                        if(sum)
                            attach(sum,a->x,a->y,a->z,&lastc);
                            a=a->next;
                            b=b->next;
                    }
                    break;
            case 1: if(starta==a) flag=1;
                        attach(a->coef,a->x,a->y,a->z,&lastc);
                    a=a->next;
                    break;
        }
    } while(!flag);
    lastc->next=c;
    lastc->next=c;
    return c;
}

void display(NODE ptr)
{
    NODE curr, temp;
    curr=ptr->next;
    while(curr!=ptr)
    {
        printf("%d*x^%d*y^%d*z^%d",curr->coef,curr->x,curr->y,curr->z);
        curr=curr->next;
        if(curr!=ptr)
            printf(" + ");
    }
}

void evaluate(NODE ptr)
{
    int ex, ey, ez, x,y, z, res=0;
    NODE curr;
    printf("Enter the  values of x, y and z");
    scanf("%d%d%d",&x,&y,&z);
    curr=ptr->next;
    while(curr!=ptr)
    {
        ex=curr->x;
        ey=curr->y;
        ez=curr->z;
        res+=curr->coef*pow(x,ex)*pow(y,ey)*pow(z,ez);
        curr=curr->next;
    }
    printf("Result =%d\t",res);
}

int main()
{
    int ch,i;
    NODE a=NULL, b, c;
    while(1)
    {
        printf("\n1.Read the polunomial A");
        printf("\n2.Read the polunomial B");
        printf("\n3. Display the polynomial A");
        printf("\n4. Display the polynomial B");
        printf("\n5.Add the polynomials");
        printf("\n6.Evaluate the polynomial");
        printf("\n7.Exit");
        printf("\n\n\nEnter the choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Reading first polynomial:\n");
                    a=readpoly();
                    break;
             case 2: printf("Reading second polynomial:\n");
                    b=readpoly();
                    break;
            case 3: display(a);
                    break;
            case 4: display(b);
                    break;
            case 5: c=addpoly(a,b);
					printf("\nThe sum of two polynomials is: ");
					display(c);
					printf("\n");
					break;
            case 6 : evaluate(c);
                    break;
            case 7: exit(1);
        }
    }
    return 0;
}
