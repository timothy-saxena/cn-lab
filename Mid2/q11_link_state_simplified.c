#include <stdio.h>
#define INF 9999

int main(void) {
    int cost[10][10], dist[10], visited[10];
    int n, i, j, s, step, u, min;

    printf("Enter number of routers: ");
    scanf("%d", &n);
    printf("Enter cost matrix (9999 = no link):\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source router (1 to %d): ", n);
    scanf("%d", &s);
    s--;

    for(i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
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
            if(!visited[j] && dist[u] + cost[u][j] < dist[j])
                dist[j] = dist[u] + cost[u][j];
        }
    }

    printf("\nSource router: %d\n", s + 1);
    printf("Destination\tCost\n");
    for(i = 0; i < n; i++)
        printf("%d\t\t%d\n", i + 1, dist[i]);

    return 0;
}
