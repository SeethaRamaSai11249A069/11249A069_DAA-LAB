#include <stdio.h>

#define MAX 100

struct Edge
{
    int u, v, w;
};

int parent[MAX];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);
    parent[rootA] = rootB;
}

int main()
{
    int n, e;
    scanf("%d %d", &n, &e);

    struct Edge edges[MAX];

    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (edges[j].w > edges[j + 1].w)
            {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int count = 0, i = 0, total = 0;

    while (count < n - 1 && i < e)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int setU = find(u);
        int setV = find(v);

        if (setU != setV)
        {
            printf("%d - %d : %d\n", u, v, w);
            total += w;
            unionSet(setU, setV);
            count++;
        }
        i++;
    }

    printf("%d\n", total);

    return 0;
}
