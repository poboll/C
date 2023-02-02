/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define red 1
#define blue 0
int flagnow = 0;
int flagnext = 0;
typedef struct Node {
    int val;
    struct Node* next;
}node;
typedef struct Q {
    int* q;
    int head, tail, count;
}Qu;
Qu* createQ(int n) {
    Qu* qu = (Qu*)malloc(sizeof(Qu));
    qu->q = (int*)malloc(sizeof(int) * n * n);
    memset(qu->q, -1, sizeof(int) * n * n);
    qu->head = 0; qu->tail = 0; qu->count = 0;
    return qu;
}
inline void enq(int i, Qu* q) {
    q->q[q->tail] = i; q->count++; q->tail++;
}
int deq(Qu* q) {
    int t = q->head;
    q->head++; q->count--;
    return q->q[t];
}
void clearQ(Qu* q, int n) {
    q->head = 0; q->tail = 0;
    memset(q->q, 0, n * n * sizeof(int));
    q->count = 0;
}
node** createmap(int n) {
    node** t = (node**)malloc(sizeof(node*) * n);
    for (int i = 0; i < n; i++) {
        node* tmp = (node*)malloc(sizeof(node));
        tmp->next = NULL;
        tmp->val = 0;
        t[i] = tmp;
    }
    return t;
}
void addEdge(int n, int target, node** map) {
    node* t = (node*)malloc(sizeof(node));
    t->val = target; t->next = map[n]->next;
    map[n]->next = t;
}
void bfs(int* ans, node** bluemap, node** redmap, int* mapred, int* mapblue, Qu* q, int v, int color, int i, int l1, int l2, int order) {
    while (1) {
        //如果没经过v点
        if (color == red) {
            mapred[v] = 1;
        }
        else {
            mapblue[v] = 1;
        }
        int num = 0;
        if (ans[v] == -1 || i < ans[v])ans[v] = i;
        printf("\n%d %d\n", v, i);
        if (color == red) {
            printf("red %d ", i);
            node* t = bluemap[v]->next;

            while (t) {
                printf("%d ", t->val);
                if (!mapblue[t->val]) {
                    q->q[q->tail] = t->val; q->tail++; q->count++;
                    //printf("%d ",t->val);
                    num++;
                }
                t = t->next;
            }
            printf("%d ", num);
            printf("count %d", num);
            flagnext += num;
            if (flagnow > 1) {
                flagnow--;

            }
            else {
                color = !color;
                flagnow = flagnext;
                flagnext = 0;
                i++;

            }
            if (q->count) {
                int tmp = q->q[q->head]; q->head++; q->count--;
                printf("flag %d %d", flagnow, flagnext);
                v = tmp;
            }
            else break;

        }
        else {
            printf("blue %d ", i);
            node* t = redmap[v]->next;
            while (t) {
                printf("%d ", t->val);
                if (!mapred[t->val]) {
                    q->q[q->tail] = t->val; q->count++; q->tail++;
                    printf("%d ", t->val);
                    num++;
                }
                t = t->next;
            }

            printf("%d ", num);
            printf("count %d ", num);
            flagnext += num;
            if (flagnow > 1) {
                flagnow--;
            }
            else {
                color = !color;
                flagnow = flagnext;
                flagnext = 0;
                i++;
            }
            if (q->count) {
                int tmp = q->q[q->head]; q->head++; q->count--;
                printf("flag %d %d", flagnow, flagnext);
                v = tmp;
            }
            else break;
        }
        printf("\n");
        order++;
    }
}
int* shortestAlternatingPaths(int n, int** redEdges, int redEdgesSize, int* redEdgesColSize, int** blueEdges, int blueEdgesSize, int* blueEdgesColSize, int* returnSize) {
    int mapred[n]; memset(mapred, 0, n * sizeof(int)); int mapblue[n]; memset(mapblue, 0, n * sizeof(int));
    node** redmap = createmap(n);
    node** bluemap = createmap(n);
    int* ans1 = (int*)malloc(sizeof(int) * n);
    memset(ans1, -1, n * sizeof(int));
    int* ans2 = (int*)malloc(sizeof(int) * n);
    memset(ans2, -1, n * sizeof(int));
    for (int i = 0; i < redEdgesSize; i++) {
        addEdge(redEdges[i][0], redEdges[i][1], redmap);
    }
    for (int i = 0; i < blueEdgesSize; i++) {
        addEdge(blueEdges[i][0], blueEdges[i][1], bluemap);
    }
    for (int i = 0; i < n; i++) {
        node* t = bluemap[i]->next;
        while (t) {
            printf("%d", t->val);
            t = t->next;
        }
        printf("\n");
    }
    Qu* q = createQ(n);
    bfs(ans1, bluemap, redmap, mapred, mapblue, q, 0, blue, 0, redEdgesSize, blueEdgesSize, 0);
    clearQ(q, n); memset(mapred, 0, n * sizeof(int)); memset(mapblue, 0, n * sizeof(int)); flagnow = flagnext = 0;
    bfs(ans2, bluemap, redmap, mapred, mapblue, q, 0, red, 0, redEdgesSize, blueEdgesSize, 0);
    for (int i = 0; i < n; i++) {
        printf("%d", ans1[i]);
        if (ans1[i] != ans2[i]) {
            if (ans1[i] == -1) {
                ans1[i] = ans2[i];
            }
            else if (ans2[i] != -1) {
                ans1[i] = ans1[i] > ans2[i] ? ans2[i] : ans1[i];
            }
        }

    }
    printf("\n");


    *returnSize = n;
    return ans1;

}