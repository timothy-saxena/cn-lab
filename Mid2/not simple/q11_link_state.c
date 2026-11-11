#include <stdio.h>
#define INF 9999

int main(void) {
  int cost[10][10], dist[10], visited[10], next[10];
  int n, i, j, s, step, u, min;

  printf("Enter number of routers: ");
  scanf("%d", &n);
  printf("Enter cost matrix (9999 = no link):\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) scanf("%d", &cost[i][j]);

  for (s = 0; s < n; s++) {
    for (i = 0; i < n; i++) {
      dist[i] = INF;
      visited[i] = 0;
      next[i] = -1;
    }
    dist[s] = 0;

    for (step = 0; step < n; step++) {
      min = INF;
      u = -1;
      for (i = 0; i < n; i++)
        if (!visited[i] && dist[i] < min) {
          min = dist[i];
          u = i;
        }
      if (u == -1) break;
      visited[u] = 1;

      for (j = 0; j < n; j++)
        if (!visited[j] && cost[u][j] != INF &&
            dist[u] + cost[u][j] < dist[j]) {
          dist[j] = dist[u] + cost[u][j];
          if (u == s)
            next[j] = j;
          else
            next[j] = next[u];
        }
    }

    printf("\nRouter %d\nDestination\tNext hop\tCost\n", s + 1);
    for (i = 0; i < n; i++) {
      if (dist[i] == INF)
        printf("%d\t\t-\t\tUnreachable\n", i + 1);
      else if (s == i)
        printf("%d\t\t-\t\t0\n", i + 1);
      else
        printf("%d\t\t%d\t\t%d\n", i + 1, next[i] + 1, dist[i]);
    }
  }
  return 0;
}
