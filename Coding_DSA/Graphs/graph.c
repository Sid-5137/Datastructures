#include <stdio.h>
#include <stdlib.h>

struct graph{
    int V;
    int E;
    int **adj;
};

struct graph* adjmatrixofgraph(){
    int u,v,i;

    struct graph* G = (struct graph*)malloc(sizeof(struct graph));
    if(G){
        printf("No memory allocated");
        return 0;
    }

    printf("Enter the number of nodes and edges: ");
    scanf("%d %d",&G->V,&G->E); 
    G->adj = malloc(sizeof(int)*(G->V*G->V));
    for(u=0;u<G->V;u++){
        for(v=0;v<G->V;v++){
            G->adj[u][v] = 0;
        }
    }

    printf("Enter the number of nodes in pairs");
    for(i=0;i<G->E;i++){
        scanf("%d %d",&u,&v);
        G->adj[u][v] = 1;
        G->adj[v][u] = 1;
    }

}

int main(){
    struct graph* adjmatrixofgraph();
    return 0;
}