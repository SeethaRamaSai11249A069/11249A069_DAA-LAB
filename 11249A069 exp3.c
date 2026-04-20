#include <stdio.h>

void firstFit(int weights[], int n, int capacity)
{
    int bin_rem[n];
    int bins = 0;

    for (int i = 0; i < n; i++)
        bin_rem[i] = capacity;

    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < bins; j++)
        {
            if (bin_rem[j] >= weights[i])
            {
                bin_rem[j] -= weights[i];
                break;
            }
        }

        if (j == bins)
        {
            bin_rem[bins] = capacity - weights[i];
            bins++;
        }
    }

    printf("%d\n", bins);
}

int main()
{
    int n, capacity;
    scanf("%d", &n);

    int weights[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &weights[i]);

    scanf("%d", &capacity);

    firstFit(weights, n, capacity);

    return 0;
}
