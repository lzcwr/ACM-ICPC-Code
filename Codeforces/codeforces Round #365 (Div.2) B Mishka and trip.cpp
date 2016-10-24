#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() /(double)CLOCKS_PER_SEC);
#define lson l, m, rt  <<  1
#define rson m + 1, r, rt  <<  1 | 1
#define root 1, n, 1

const int maxn = 100005;
const int maxm = 1e5 + 5;
const int mod = 10000;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const int MAX_N = 50005;

int cap[maxn], c[maxn];
bool vis[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, k;
    scanf("%d%d", &n, &k);

    long long sum(0);
    memset(vis, false, sizeof(vis));

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
        sum += c[i];
    }

    long long ans = c[0] * c[n - 1];
    for(int i = 0; i < n - 1; i++)
        ans += c[i] * c[i + 1];

    for(int i = 0; i < k; i++)
    {
        int m;
        scanf("%d", &m);
        if(m == 1)
        {
            if(vis[n]) ans += c[m - 1] * c[n - 1];
            if(vis[m + 1]) ans += c[m] * c[m - 1];
            ans += c[m - 1] * (sum - c[m - 1] - c[m] - c[n - 1]);
        }
        else if(m == n)
        {
            if(vis[m - 1]) ans += c[m - 1] * c[m - 2];
            if(vis[1]) ans += c[m - 1] * c[0];
            ans += c[m - 1] * (sum - c[m - 1] - c[m - 2] - c[0]);
        }
        else
        {
            if(vis[m - 1]) ans += c[m - 1] * c[m - 2];
            if(vis[m + 1]) ans += c[m - 1] * c[m];
            ans += c[m - 1] * (sum - c[m - 1] - c[m - 2] - c[m]);
        }
        vis[m] = true;
        sum -= c[m - 1];
    }
    printf("%lld\n", ans);

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("out.txt");
#endif

    return 0;
}

