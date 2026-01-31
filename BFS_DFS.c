#include<stdio.h>

#define MAX 5

void bfs(int adj[][MAX], int visited[],int start)
{
    int Q[MAX], rear=-1,front=-1,k;

    for(k=0;k<MAX;k++)
        visited[k]=0;
    Q[++rear]=start;
    ++front;
    visited[start]=1;

    while(rear>=front)
    {
        start=Q[front++];
        printf("%d",start);

        for(int i=0;i<MAX;i++)
        {
            if(adj[start][i] && visited[i]==0)
            {
                Q[++rear] =i;
                visited[i]=1;
            }
        }
    }
}
int main()
{
    int visited[MAX]={0};
    int adj[MAX][MAX], i,j;
    int choice,size;

    do{
        printf("\nMENU ---");
        printf("\n1.Enter Values  in Graph");
        printf("\n2. Perform BFS");
        printf("\n3.Exit");
        printf("\nEnter your choice: from 1 to 3 as per above menu:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("\nadjacency matrix:");
            for(i=0;i<MAX;i++)
            {
                for(j=0;j<MAX;j++)
                {
                    scanf("%d",&adj[i][j]);
                }
            }
            break;
            case 2:
            printf("\nResult of BFS operation:  ");
            bfs(adj,visited,0);
            break;
            case 3:
            printf("\nclosing the operations:");
            break;

            default:
            printf("Invalid User Input, Enter input from 1 - 3 only");

        }
    }while (choice!=3);
   return 0;   

}
