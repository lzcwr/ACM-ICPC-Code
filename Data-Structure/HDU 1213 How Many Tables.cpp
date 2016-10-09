#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
// #include <cstdio>
// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <cmath>
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt  <<  1
#define rson m + 1, r, rt  <<  1 | 1
#define root 1, n, 1

const int maxn = 1010;
const int maxm = 1e5 + 5;
const int mod = 10000;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;

int fa[maxn];
int find(int x)
{
    if(fa[x] == -1) return x;
    return fa[x] = find(fa[x]);
}

void link(int x, int y)
{
    int f1 = find(x), f2 = find(y);
    if(f1 != f2) fa[f1] = f2;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(fa, -1, sizeof(fa));
        while(m--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            link(a, b);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(fa[i] == -1) ans++;
        printf("%d\n", ans);
    }

    return 0;
}
