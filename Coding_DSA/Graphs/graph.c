#include <stdio.h>
#include <stdlib.h>

struct graph {
    int V;
    int E;
    int **adj;
};

struct graph* adjmatrixofgraph() {
    int u, v, i;

    struct graph* G = (struct graph*)malloc(sizeof(struct graph));
    if (!G) {
        printf("No memory allocated\n");
        return NULL;
    }

    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &G->V, &G->E);
    
    G->adj = (int **)malloc(sizeof(int*) * G->V);
    for (u = 0; u < G->V; u++) {
        G->adj[u] = (int *)malloc(sizeof(int) * G->V);
        for (v = 0; v < G->V; v++) {
            G->adj[u][v] = 0;
        }
    }

    printf("Enter the pairs of nodes:\n");
    for (i = 0; i < G->E; i++) {
        scanf("%d %d", &u, &v);
        G->adj[u][v] = 1;
        G->adj[v][u] = 1;
    }

    return G;
}

int main() {
    struct graph* G = adjmatrixofgraph();
    
    if (G) {
        // Print the adjacency matrix
        printf("Adjacency Matrix:\n");
        for (int u = 0; u < G->V; u++) {
            for (int v = 0; v < G->V; v++) {
                printf("%d ", G->adj[u][v]);
            }
            printf("\n");
        }

        // Free allocated memory
        for (int u = 0; u < G->V; u++) {
            free(G->adj[u]);
        }
        free(G->adj);
        free(G);
    }

    return 0;
}
