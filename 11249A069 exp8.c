#include <stdio.h>

#define V 20

int min(int a, int b)
{
    return a < b ? a : b;
}

int dfs(int rGraph[V][V], int s, int t, int visited[], int parent[], int n)
{
    visited[s] = 1;

    if (s == t)
        return 1;

    for (int v = 0; v < n; v++)
    {
        if (!visited[v] && rGraph[s][v] > 0)
        {
            parent[v] = s;
            if (dfs(rGraph, v, t, visited, parent, n))
                return 1;
        }
    }
    return 0;
}

int fordFulkerson(int graph[V][V], int n, int s, int t)
{
    int u, v;
    int rGraph[V][V];

    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0;

    while (1)
    {
        int visited[V] = {0};

        if (!dfs(rGraph, s, t, visited, parent, n))
            break;

        int path_flow = 99999;

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    int n, graph[V][V];
    int s, t;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    scanf("%d %d", &s, &t);

    printf("%d\n", fordFulkerson(graph, n, s, t));

    return 0;
}
