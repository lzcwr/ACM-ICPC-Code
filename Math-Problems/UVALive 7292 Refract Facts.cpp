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

void solve()
{
    double d, h, x, n1, n2;
    while(scanf("%lf%lf%lf%lf%lf", &d, &h, &x, &n1, &n2) != EOF)
    {
        if(d == 0 && h == 0 && x == 0 && n1 == 0 && n2 == 0) break;
        double l = 0, r = x, m;  
        for(int i = 0; i < 100; i++)
        {  
            m = (l + r) / 2;  
            double t1 = (x - m) / d;
            double t2 = m / h;  
            double f = t1 * t1 * (t2 * t2 + 1) / ((t1 * t1 + 1) * t2 * t2) - n1 * n1 / n2 / n2;  
            if(f < 0) r = m;  
            else l = m;  
        }  
        double ans = atan(d / (x - l)) / pi * 180;  
        printf("%.2lf\n", ans);
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
