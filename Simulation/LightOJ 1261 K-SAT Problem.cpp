#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt  <<  1
#define rson m + 1, r, rt  <<  1 | 1
#define root 1, n, 1

const int maxn = 1005;
const int maxm = 1e5 + 5;
const int mod = 10000;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;

int mp[55][55];
bool vis[maxn];
std::set<int> s;

void init()
{
    s.clear();
    memset(vis, false, sizeof(vis));
}

bool judge(int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        bool state = false;
        for (int j = 1; j <= k; j++)
        {
            if(s.count(mp[i][j]))
            {
                state = true;
                break;
            }
        }
        if(!state) return false;
    }
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    int cas(0);
    while(t--)
    {
        init();
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= k; j++)
                scanf("%d", &mp[i][j]);
        int p;
        scanf("%d", &p);
        while(p--)
        {
            int tmp;
            scanf("%d", &tmp);
            s.insert(tmp);
            vis[tmp] = true;
        }
        for(int i = 1; i <= m; i++)
            { if(!vis[i]) s.insert(-i); }

        if(judge(n, k)) printf("Case %d: Yes\n", ++cas);
        else printf("Case %d: No\n", ++cas);
    }

    return 0;
}
