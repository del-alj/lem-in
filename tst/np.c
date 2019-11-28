#include <stdio.h>

int matrix[100000][100000];

int main()
{
    int i, n, m, k, u, v, a;

    i = 0;
    scanf("%d%d%d", &n, &m, &k);
    while (i < m)
    {
        scanf("%d%d", &u, &v);
        if (matrix[u][v] != 1)
        {
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }
        i++;
    }
    i =  m - n + k;
    if (i <= 0)
        printf("-1\n");
    else
        printf("%d\n", i);
    return (0);
}