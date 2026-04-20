#include <stdio.h>
#include <limits.h>

#define V 20

int minDistance(int dist[], int visited[], int n)
{
    int min = INT_MAX, min_index = -1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dist[i] <= min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int n, int src)
{
    int dist[V], visited[V];

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);
}

int main()
{
    int n, graph[V][V], src;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}
