#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt  <<  1
#define rson m + 1, r, rt  <<  1 | 1
#define root 1, n, 1

const int maxn = 200005;
const int maxm = 1e5 + 5;
const int mod = 10000;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;

int fa[maxn], weight[maxn];
int find(int x)
{
    if(fa[x] == x) return x;
    int ret = fa[x];
    fa[x] = find(fa[x]);
    weight[x] += weight[ret];
    return fa[x];
}

void Union(int x, int y, int val)
{
    int f1 = find(x), f2 = find(y);
    if(f1 != f2)
    {
        fa[f2] = f1;
        weight[f2] = weight[x] - weight[y] + val;
    }
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 0; i <= n; i++)
            fa[i] = i, weight[i] = 0;
        int ans = 0;
        while(m--)
        {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w); a--;
            if(find(a) == find(b))
            {
                if(weight[b] - weight[a] != w)
                    ans++;
            }
            else Union(a, b, w);
        }
        printf("%d\n", ans);
    }

    return 0;
}
