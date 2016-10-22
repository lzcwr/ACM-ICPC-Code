#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

const int maxn = 2e5 + 5;
const int maxm = 1005;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
// const int inf = std::numeric_limits<int>::max();
const int inf = 0x3f3f3f3f;

long long ans, sum;
int a[maxn], vis[maxn], dep[maxn];

void init()
{
    ans = 1; sum = 0;
    memset(vis, 0, sizeof(vis));
}

long long pow_mod(long long a, long long n, long long p)
{
    long long ret = 1;
    while(n)
    {
        if(n & 1) ret = ret * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ret;
}

void dfs(int cur, int _dep, int fa)
{
    vis[cur] = fa;
    dep[cur] = _dep;
    if(!vis[a[cur]])
        dfs(a[cur], _dep + 1, fa);
    else if(vis[a[cur]] == fa)
    {
        ans = ans * (pow_mod(2, dep[cur] - dep[a[cur]] + 1, mod) - 2 + mod) % mod;
        sum += dep[cur] - dep[a[cur]] + 1;
    }
}

int main()
{
    init();
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for(int i = 1; i <= n; i++)
        if(!vis[i]) dfs(i, 0, i);
    ans = ans * pow_mod(2, n - sum, mod) % mod;

    printf("%lld\n", ans);

    return 0;
}
