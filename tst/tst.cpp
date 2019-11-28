
// #include <stdio.h>
// #include <iostream>
// using namespace std;
// int matrix[1001][1001];
 
// int main()
// {
//     // ios_base::sync_with_stdio(false);
//     // cin.tie(NULL);
//     // cout.tie(NULL);
//     int i,m,n,q,a,b;
//     cin >> n >> m;
//     for(i=1;i<=m;i++)c
//     {
//         cin >> a >> b ;
//         matrix[a][b] = 1;
//         matrix[b][a] = 1;
//     }
//     cin >> q;
//     for(i=1;i<=q;i++)
//     {
//         cin >> a >> b;
//         if(matrix[a][b]==1)
//         printf("YES\n");
//         else
//         printf("NO\n");
//     }
//     return 0;
// }
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