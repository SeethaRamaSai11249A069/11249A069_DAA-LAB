#include <stdio.h>

struct Item
{
    int weight;
    int value;
    float ratio;
};

void sort(struct Item items[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (items[i].ratio < items[j].ratio)
            {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Item items[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    int capacity;
    scanf("%d", &capacity);

    sort(items, n);

    float totalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (capacity >= items[i].weight)
        {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            totalValue += items[i].ratio * capacity;
            break;
        }
    }

    printf("%.2f\n", totalValue);

    return 0;
}
