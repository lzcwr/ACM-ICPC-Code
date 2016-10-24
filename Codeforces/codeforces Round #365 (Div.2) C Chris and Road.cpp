#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() /(double)CLOCKS_PER_SEC);
#define lson l, m, rt  <<  1
#define rson m + 1, r, rt  <<  1 | 1
#define root 1, n, 1

const int maxn = 1e4 + 5;
const int maxm = 1e5 + 5;
const int mod = 10000;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const int MAX_N = 50005;

std::pair<double, double> p[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    double u, v, w;
    scanf("%d%lf%lf%lf", &n, &w, &v, &u);
    for(int i = 0; i < n; i++)
        scanf("%lf%lf", &p[i].first, &p[i].second);
    double ans = (w / u);
    bool state = true;
    for(int i = 0; i < n; i++)
    {
        if(p[i].second / u > p[i].first / v || p[i].first < 0)
            state = false;
        double tmp = max( p[i].first / v, p[i].second / u );
        ans = max( ans, tmp + (w - p[i].second) / u );
    }

    if(!state) printf("%.12f\n", ans);
    else printf("%.12f\n", w / u);

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("out.txt");
#endif

    return 0;
}

