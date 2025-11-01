//DFS Traversal
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int v;
    struct node* next;
}node;

typedef struct graph{
    int count;
    node **adj;
}graph;

void addedge(graph *G, int u, int v){
    node *n1=(node*)malloc(sizeof(node));
    n1->v=v; n1->next=G->adj[u]; G->adj[u]=n1;
    
    node *n2=(node*)malloc(sizeof(node));
    n2->v=u; n2->next=G->adj[v]; G->adj[v]=n2;
}

void dfs(graph *G,int start,int *visited){
    visited[start]=1;
    printf("%d ",start);
    node *t=G->adj[start];
    while(t){
        if(!visited[t->v]){
            dfs(G,t->v,visited);
        }
        t=t->next;
    }
}

int main() {
    int V,e;
    printf("Enter the number of vertices:");
    scanf("%d",&V);
    printf("Enter the number of edges:");
    scanf("%d",&e);
    graph *G=(graph*)malloc(sizeof(graph));
    G->count=V;
    G->adj=(node**)calloc(V,sizeof(node*));
    int u,v;
    printf("Enter edges: \n");
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d",&u,&v);
        addedge(G,u,v);
    }
    int start;
    printf("Enter starting vertex: ");
    scanf("%d",&start);
    int *visited=(int*)calloc(V,sizeof(int));
    if(start>=0 && start<V){
        dfs(G,start,visited);
        for (int i = 0; i < V; i++)
        {
            if(!visited[i]) dfs(G,i,visited);
        }
        
    }
    
    //Cleanup
    for (int i = 0; i < V; i++)
    {
        node *curr=G->adj[i];
        while(curr){
            node *temp=curr;
            curr=curr->next;
            free(temp);
        }
    }
    free(G->adj);
    free(G);
    free(visited);
    
    return 0;
}
