#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max_Vertices 50

typedef struct graph_t{
	int V;
	bool adj[Max_Vertices][Max_Vertices];
}graph;

graph* graph_create(int V){
	graph* g = malloc(sizeof(graph));
	g->V = V;

	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			g->adj[i][j] = false;
		}
	}
	return g;
}

void graph_destroy(graph* g){free(g);}

void graph_addedge(graph* g,int u,int v){
	g->adj[u][v] = true;
}

void graph_bfs(graph* g,int s){
	bool visited[Max_Vertices];
	for(int i=0;i<Max_Vertices;i++){
		visited[i] = false;
	}

	int queue[Max_Vertices];
	int front = 0;int rear = 0;

	visited[s] = true;
	queue[rear++] = s;

	while(front != rear){
		s = queue[front++];
		printf("%d",s);

		for(int i=0;i<g->V;i++){
			if(g->adj[s][i] && !visited[i]){
				visited[i] = true;
				queue[rear++] = i;
			}
		}
	}
}

int main(){
	graph* g = graph_create(1);
	return 0;
}