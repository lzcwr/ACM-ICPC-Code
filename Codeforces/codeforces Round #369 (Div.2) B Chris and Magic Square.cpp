#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

const int maxn = 505;
const int maxm = 1005;
const int mod = 10000;
const double eps = 1e-8;
const double pi = acos(-1.0);
// const int inf = std::numeric_limits<int>::max();
const int inf = 0x3f3f3f3f;

long long mat[maxn][maxn], r[maxn], c[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    long long ans = -1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%lld", &mat[i][j]);

    for(int i = 0; i < n; i++)
    {
        r[i] = 0;
        for(int j = 0; j < n; j++)
            r[i] += mat[i][j];
    }
    sort(r, r + n);
    if(n == 1) ans = 1;
    else
    {
        long long res = r[1] - r[0];
        if(n > 2 && r[2] != r[1]) ans = -1;
        else
        {
            for(int i = 0; i < n; i++)
            {
                c[i] = 0;
                for(int j = 0; j < n; j++)
                {
                    c[i] += mat[j][i];
                    if(mat[j][i] == 0) c[i] += res;
                }
            }
            sort(c, c + n);
            if(c[0] != c[1]) ans = -1;
            else
            {
                long long s1(0), s2(0);
                for(int i = 0; i < n; i++)
                {
                    s1 += mat[i][i];
                    if(mat[i][i] == 0) s1 += res;
                }
                for(int i = 0, j = n - 1; i < n; i++, j--)
                {
                    s2 += mat[i][j];
                    if(mat[i][j] == 0) s2 += res;
                }
                if(s1 != s2) ans = -1;
                else if(s1 != r[n - 1] || s1 != c[n - 1]) ans = -1;
                else ans = res;
            }
        }
    }
    if(ans == 0) ans = -1;
    printf("%lld\n", ans);

    return 0;
}
