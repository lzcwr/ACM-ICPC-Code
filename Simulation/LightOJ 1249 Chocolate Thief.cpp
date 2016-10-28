#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

const int maxn = 10005;
const int maxm = 1005;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;

struct Node
{
    char name[105];
    int val;
    bool operator < (const Node &b) const
    {
        return val < b.val;
    }
} p[maxn];

void solve()
{
    int t, cas(0);
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int x, y, z;
        for(int i = 0; i < n; i++)
        {
            scanf("%s%d%d%d", p[i].name, &x, &y, &z);
            p[i].val = x * y * z;
        }
        sort(p, p + n);
        if(p[0].val == p[n - 1].val)
            printf("Case %d: no thief\n", ++cas);
        else
            printf("Case %d: %s took chocolate from %s\n", ++cas, p[n - 1].name, p[0].name);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    solve();

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("out.txt");
#endif

    return 0;
}
