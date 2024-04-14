#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    int src, dest, weight;
} Edge;

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot;
}

int compareEdges(const void *a, const void *b) {
    Edge *edge1 = (Edge *)a;
    Edge *edge2 = (Edge *)b;
    return edge1->weight - edge2->weight;
}

void createGraph(int n, int m, int graph[n][n]) {
    printf("输入边依附的顶点及权值，例如：a b 6:\n");
    for (int i = 0; i < m; i++) {
        char src, dest;
        int weight;
        scanf(" %c %c %d", &src, &dest, &weight);
        graph[src - 'a'][dest - 'a'] = weight;
        graph[dest - 'a'][src - 'a'] = weight;
    }
    printf("图的邻接矩阵为:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void prim(int n, int graph[n][n]) {
    int parent[n];
    int key[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int min = INT_MAX, minIndex;

        for (int v = 0; v < n; v++) {
            if (visited[v] == 0 && key[v] < min) {
                min = key[v];
                minIndex = v;
            }
        }

        int u = minIndex;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && visited[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("普里姆算法生成树为:\n");
    for (int i = 1; i < n; i++) {
        printf("%c - %c, weight: %d\n", 'a' + parent[i], 'a' + i, graph[i][parent[i]]);
    }
}

void kruskal(int n, int graph[n][n]) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j]) {
                m++;
            }
        }
    }

    Edge edges[m];
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j]) {
                edges[k].src = i;
                edges[k].dest = j;
                edges[k].weight = graph[i][j];
                k++;
            }
        }
    }

    qsort(edges, m, sizeof(Edge), compareEdges);

    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    printf("克鲁斯卡尔算法生成树为:\n");
    for (int i = 0, e = 0; e < n - 1 && i < m; i++) {
        int x = find(parent, edges[i].src);
        int y = find(parent, edges[i].dest);

        if (x != y) {
            printf("%c - %c, 权重: %d\n", 'a' + edges[i].src, 'a' + edges[i].dest, edges[i].weight);
            Union(parent, x, y);
            e++;
        }
    }
}

int main() {
    int n, m;
    printf("请输入总顶点数: ");
    scanf("%d", &n);
    printf("请输入总边数: ");
    scanf("%d", &m);

    int graph[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    createGraph(n, m, graph);
    prim(n, graph);
    kruskal(n, graph);

    return 0;
}
