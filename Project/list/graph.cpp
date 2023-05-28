#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

typedef struct {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

typedef struct {
    int start, end, weight;
} Edge;

// 初始化图
void init_graph(Graph *g, int num_vertices) {
    g->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++)
        for (int j = 0; j < num_vertices; j++)
            g->vertices[i][j] = (i == j) ? 0 : INF;
}

// 添加边
void add_edge(Graph *g, int start, int end, int weight) {
    g->vertices[start][end] = weight;
    g->vertices[end][start] = weight;
}

// Prim算法
void prim(Graph *g) {
    int min_distance[g->num_vertices];
    int visited[g->num_vertices];

    for (int i = 0; i < g->num_vertices; i++) {
        min_distance[i] = INF;
        visited[i] = 0;
    }

    min_distance[0] = 0;
    int total_weight = 0;

    for (int i = 0; i < g->num_vertices; i++) {
        int min_vertex = -1;
        for (int j = 0; j < g->num_vertices; j++) {
            if (!visited[j] && (min_vertex == -1 || min_distance[j] < min_distance[min_vertex]))
                min_vertex = j;
        }

        visited[min_vertex] = 1;
        total_weight += min_distance[min_vertex];

        for (int j = 0; j < g->num_vertices; j++) {
            if (!visited[j] && g->vertices[min_vertex][j] < min_distance[j])
                min_distance[j] = g->vertices[min_vertex][j];
        }
    }

    printf("Prim: Minimum weight = %d\n", total_weight);
}

// 辅助函数：比较边的权重
int compare_edges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

// 查找并查集的根节点
int find_set(int parent[], int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find_set(parent, parent[x]);
}

// 合并两个并查集
void union_sets(int parent[], int x, int y) {
    int root_x = find_set(parent, x);
    int root_y = find_set(parent, y);
    if (root_x != root_y)
        parent[root_y] = root_x;
}

// Kruskal算法
void kruskal(Graph *g) {
    Edge edges[MAX_VERTICES * (MAX_VERTICES - 1) / 2];
    int num_edges = 0;

    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = i + 1; j < g->num_vertices; j++) {
            if (g->vertices[i][j] != INF) {
                edges[num_edges].start = i;
                edges[num_edges].end = j;
                edges[num_edges].weight = g->vertices[i][j];
                num_edges++;
            }
        }
    }

    qsort(edges, num_edges, sizeof(Edge), compare_edges);

    int parent[MAX_VERTICES];
    for (int i = 0; i < g->num_vertices; i++)
        parent[i] = i;

    int total_weight = 0;

    for (int i = 0; i < num_edges; i++) {
        int start = edges[i].start;
        int end = edges[i].end;
        if (find_set(parent, start) != find_set(parent, end)) {
            total_weight += edges[i].weight;
            union_sets(parent, start, end);
        }
    }

    printf("Kruskal: Minimum weight = %d\n", total_weight);
}

int main() {
    Graph g;
    init_graph(&g, 6);

    add_edge(&g, 0, 1, 6);
    add_edge(&g, 0, 2, 1);
    add_edge(&g, 0, 3, 5);
    add_edge(&g, 1, 2, 5);
    add_edge(&g, 1, 4, 3);
    add_edge(&g, 2, 3, 5);
    add_edge(&g, 2, 4, 6);
    add_edge(&g, 2, 5, 4);
    add_edge(&g, 3, 5, 2);
    add_edge(&g, 4, 5, 6);

    prim(&g);
    kruskal(&g);

    return 0;
}
