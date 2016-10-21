#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt  <<  1
#define rson m + 1, r, rt  <<  1 | 1
#define root 1, n, 1

const int maxn = 105;
const int maxm = 1e5 + 5;
const int mod = 10000;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;

int a[maxn];

int main()
{
    int n;
    double sum(0), ans(0);
    while(scanf("%d", &n) != EOF)
    {
        sum = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            sum += (double)a[i];
        }
        ans = (double) sum * 1.0 / n;
        printf("%.12f\n", ans);
    }

    return 0;
}
