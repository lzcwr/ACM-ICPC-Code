#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 305;

int a[maxn][maxn];
int ans[maxn], send[maxn], idx[maxn];

void init()
{
    memset(a, 0, sizeof(a));
    memset(send, 0, sizeof(send));
    memset(idx, 0, sizeof(idx));
}

int main()
{
    init();
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[0][i]);
        idx[a[0][i]] = i;
    }

    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(a[0][i] > a[0][j])
            {
                if(send[i] == 0)
                    send[i] = a[0][j];
                else
                {
                    send[i] = -1;
                    break;
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i][j] == i)
                continue;

            int k = idx[a[i][j]];

            if(!send[k] || send[k] == i)
            {
                ans[i] = a[i][j];
                break;
            }
        }
    }

    for(int i=1; i<=n; i++)
        printf("%d%c", ans[i], i==n?'\n':' ');

    return 0;
}
