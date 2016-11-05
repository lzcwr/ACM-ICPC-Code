#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

const int maxn = 1e6 + 5;
const int maxm = 1005;
const int mod = 1e6 + 3;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;

void solve()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int ans(0);
        while(n--)
        {
            char op[5];
            scanf("%s", op);
            if(op[0] == 'S') ans++;
            else
            {
                int d;
                scanf("%d", &d);
                if(d == 1) ans++;
            }
        }
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
