#include <stdio.h>
#include <limits.h>

#define MAX 100

struct Edge
{
    int u, v, w;
};

int main()
{
    int n, e;
    scanf("%d %d", &n, &e);

    struct Edge edges[MAX];

    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    int src;
    scanf("%d", &src);

    int dist[MAX];

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);

    return 0;
}
