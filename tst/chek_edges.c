#include <stdio.h>

int main()
{
    int matrix[1001][1001];
    int i,m,n,q,a,b;

    i = 0;
    scanf("%d%d",&n, &m);
    while (i < m)
    {
        scanf("%d%d",&a, &b);
        matrix[a][b] = 1;
        matrix[b][a] = 1;
        i++;
    }
    scanf("%d",&q);
    i = 0;
    while (i < q)
    {
        scanf("%d%d",&a, &b);
        if(matrix[a][b] == 1)
            printf("YES\n");
        else
            printf("NO\n");
        i++;
    }
    return (0);
}