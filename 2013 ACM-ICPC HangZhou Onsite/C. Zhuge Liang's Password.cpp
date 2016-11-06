#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n",  clock() / (double)CLOCKS_PER_SEC);

const int maxn = 35;
const int maxm = 100005;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int inf = 0x7f7f7f7f;
const int INF = 1 << 28;

int a[maxn][maxn], b[maxn][maxn];
void solve()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0) break;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &b[i][j]);

        int ans = 0;
        int cnt90(0), cnt180(0), cnt270(0);
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] == b[i][j]) ans++;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(a[j][n - i - 1] == b[i][j]) cnt90++;
            if(a[n - i - 1][n - j - 1] == b[i][j]) cnt180++;
            if(a[n - j - 1][i] == b[i][j]) cnt270++;
        }
        ans = max(cnt270, max(cnt180, max(cnt90, ans)));
        printf("%d\n", ans);
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
