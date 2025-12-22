#ifndef GRAPH_H
#define GRAPH_H

/*
===============================================================================
GRAPH — ATTACK SPREAD MODEL
===============================================================================
*/

typedef struct AdjNode {
    int dest;
    struct AdjNode *next;
} AdjNode;

typedef struct {
    int num_vertices;
    AdjNode **adj_lists;
} Graph;

Graph* graph_create(int vertices);
void graph_add_edge(Graph *graph, int src, int dest);
void bfs(Graph *graph, int start);
void dfs(Graph *graph, int start);
void graph_free(Graph *graph);

#endif
