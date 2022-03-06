//Tree operations


#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node * left;
    struct node * right;
    int data;
};
typedef struct node * Node;

Node create(int item)
{
    Node temp;
    temp=(Node)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=item;
    return temp;
}

Node insert(Node node, int key)
{
    if(node==NULL)
        return create(key);
    if(key<node->data)
        node->left= insert(node->left,key);
    else if(key>node->data)
        node->right= insert(node->right,key);
    return node;
}

int search(Node root, int key)
{
    if(root==NULL)
        return -1;
    if(root->data==key)
        return 1;
    if(root->data>key)
        return search(root->left,key);
    return search(root->right,key);
}

void preorder(Node root)
{
    if(root!=NULL)
    {
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

void postorder(Node node)
{
    if(node!=NULL)
    {
    postorder(node->left);
    postorder(node->right);
    printf("%d\t",node->data);
    }
}

void inorder(Node root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
    }
}

int main()
{
    int ch, ch1, n,i,key,pos,ele;
    Node root=NULL;
    printf("Enter the number of elements to be inserted:\t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the element to be inserted:\t");
        scanf("%d",&key);
        root=insert(root,key);
    }
    while(1)
    {
        printf("\nMenu\n");
        printf("\n1.Insert\n2.Traverse\n3.Search\n4.Exit\n");
        printf("Enter your choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:  printf("Enter the element to be inserted:\t");
                     scanf("%d",&key);
                     root=insert(root,key);
                     break;
            case 2: printf("\n1.Preorder\n2.Postorder\n3.Inorder\n");
                    printf("Enter the choice:\t");
                    scanf("%d",&ch1);
                    switch(ch1)
                    {
                        case 1: preorder(root);
                                break;
                        case 2: postorder(root);
                                break;
                        case 3: inorder(root);
                                break;
                    }
                    break;
            case 3: printf("Enter the element to be searched\t");
                    scanf("%d",&key);
                    pos=search(root,key);
                    if(pos==1)
                        printf("Key is found\n");
                    else if(pos==-1)
                        printf("Key is not found\n");
                    break;
            case 4: exit(1);
        }
    }
    return 0;
}
