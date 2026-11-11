#include <stdio.h>
#define INF 9999

int cost[10][10], dist[10], visited[10], parent[10];

void printPath(int v) {
    if(parent[v] != -1) {
        printPath(parent[v]);
        printf(" -> ");
    }
    printf("%d", v + 1);
}

int main(void) {
    int n, i, j, s, step, u, min;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix (9999 = no link):\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source (1 to %d): ", n);
    scanf("%d", &s);
    s--;

    for(i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[s] = 0;

    for(step = 0; step < n; step++) {
        min = INF;
        u = -1;

        for(i = 0; i < n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        for(j = 0; j < n; j++) {
            if(!visited[j] && cost[u][j] != INF &&
               dist[u] + cost[u][j] < dist[j]) {

                dist[j] = dist[u] + cost[u][j];
                parent[j] = u;
            }
        }
    }

    printf("Node\tCost\tPath\n");

    for(i = 0; i < n; i++) {
        if(dist[i] == INF)
            printf("%d\tUnreachable\n", i + 1);
        else {
            printf("%d\t%d\t", i + 1, dist[i]);
            printPath(i);
            printf("\n");
        }
    }

    return 0;
}