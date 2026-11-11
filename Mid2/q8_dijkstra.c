#include <stdio.h>
#define INF 9999

int main(void) {
    int cost[10][10], dist[10], visited[10];
    int n, i, j, s, step, u, min;

    // inputs to the question
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter cost matrix (9999 = no link):\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source (1 to %d): ", n);
    scanf("%d", &s);
    s--;

    // initializing starting values
    for(i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[s] = 0;

    for(step = 0; step < n; step++) {
        // for every node we set the min to INF and set selection router as -1
        min = INF;
        u = -1;
        // finding min distance
        for(i = 0; i < n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }
        // if no router is present
        if(u == -1)
            break;
        // selecting the router
        visited[u] = 1;

        // updating distance
        for(j = 0; j < n; j++) {
            if(!visited[j] && dist[u] + cost[u][j] < dist[j])
                dist[j] = dist[u] + cost[u][j];
        }
    }
    // printing nodes and costs
    printf("Node\tCost\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\n", i + 1, dist[i]);

    return 0;
}
