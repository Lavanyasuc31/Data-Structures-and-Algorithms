//Graph traversal( bfs and dfs)


#include<stdio.h>
#include<stdlib.h>

int a[20][20], f=0, r=-1,q[20], visited[20], reach[20],v,n,i,count=0;

void bfs(int v)
{
    for(i=0;i<=n;i++)
    {
        if(a[v][i]&&!visited[i])
        {
            q[++r]=i;
        }
    }
    if(f<=r)
    {
        visited[q[f]]=1;
        bfs(q[f++]);
    }
}

void dfs(int v)
{
    reach[v]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[v][i]&&!reach[i])
        {
            printf("\n%d->%d",v,i);
            count++;
            dfs(i);
        }
    }
}

int main()
{
    int ch;
    printf("Enter the number of vertices:\t");
    scanf("%d",&n);
    printf("\nEnter the graph data in the form of matrix:\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        visited[i]=0;
        q[i]=0;
    }
    for(int i=1;i<=n-1;i++)
    {
        reach[i]=0;
    }
    while(1)
    {
        printf("\nMenu\n");
        printf("\n1.BFS\n2.DFS\n3.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the starting vertex:\t");
                    scanf("%d",&v);
                    if(v<1||v>n)
                    {
                        printf("Invalid vertex\n");
                    }
                    else
                    {
                        bfs(v);
                        printf("The visited cities are:\n");
                        for(int i=1;i<=n;i++)
                        {
                            if(visited[i])
                                printf("%d\t",i);
                        }
                    }
                    break;
            case 2: dfs(1);
                    if(count==n-1)
                        printf("\nthe graph is connected\n");
                    else
                        printf("The graph is not connected\n");
                    break;
            case 3: exit(1);
        }
    }
    return 0;
}
