#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int v;
    node *next;
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

void dfs(graph *G, int start, int *visited){
    int* stack=(int*)malloc(G->count*sizeof(int));
    int top=-1;
    stack[++top]=start;
    visited[start]=1;
    while(top!=-1){
        int n=stack[top--];
        printf("%d ",n);

        node *t=G->adj[n];
        while(t){
            if(!visited[t->v]){
                visited[t->v]=1;
                stack[++top]=t->v;
            }
            t=t->next;
        }
        
    }
}
int main(){
    int V,e;
    printf("Vertices: ");
    scanf("%d",&V);
    if(V<1){
        printf("Invalid");
        return 1;
    }
    printf("Edges: ");
    scanf("%d",&e);
    if(e<0){
        printf("Invalid");
        return 1;
    }
    graph *G=(graph*)malloc(sizeof(graph));
    G->count=V;
    G->adj=(node**)calloc(V,sizeof(node*));
    int u,v;
    printf("Enter edges: \n");
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d",&u,&v);
        if((u<0 || u>V-1)|| (v<0 || v>V-1)){
            printf("Invalid");
            return 1;
        }
        addedge(G,u,v);
    }
    int *visited=(int*)calloc(V,sizeof(int));
    int start;
    printf("Enter starting vertex: ");
    scanf("%d",&start);
    if(start<0 || start>V-1){
        printf("Invalid");
        return 1;
    }
    else{
        dfs(G,start,visited);
    }

    
    return 0;
}