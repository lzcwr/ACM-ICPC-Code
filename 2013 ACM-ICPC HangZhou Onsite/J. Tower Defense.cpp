#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n",  clock() / (double)CLOCKS_PER_SEC);

const int maxn = 205;
const int maxm = 100005;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int inf = 0x7f7f7f7f;
const int INF = 1 << 28;

long long C[maxn][maxn], fac[maxn << 1], sum[maxn][maxn], double_fac[maxn << 1];

void init()
{
    C[0][0] = 1;
    for(long long i = 1; i < maxn - 1; i++)
    {
        C[i][0] = C[i][i] = 1;
        for(long long j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }

    fac[0] = 1;
    for(long long i = 1; i < 2 * maxn - 1; i++)
        fac[i] = fac[i - 1] * i % mod;

    for(long long i = 0; i < maxn - 1; i++)
        sum[i][0] = 1;
    for(long long i = 0; i < maxn - 1; i++)
    for(long long j = 1; j < maxn - 1; j++)
            sum[i][j] = (C[i][j] + sum[i][j - 1]) % mod;

    double_fac[1] = 1;
    for(long long i = 1; i < 2 * maxn - 1; i++)
        if(i > 1 && (i & 1)) double_fac[i] = (double_fac[i - 2] * i) % mod;
}

void solve()
{
    init();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        long long n, m, p, q;
        long long tmp;
        scanf("%lld%lld%lld%lld", &n, &m, &p, &q);
        long long ans(0);
        for(long long i = 0; i <= n; i++)
        {
            for(long long j = 0; j <= m; j++)
            {
                if(i + 2 * j > n || j + 2 * i > m || 2 * i + 2 * j > p) break;
                if(2 * i - 1 > 0) tmp = double_fac[2 * i - 1];
                else tmp = 1;
                long long res = C[n][i] * C[m][2 * i] % mod * tmp % mod * fac[i] % mod;
                if(2 * j - 1 > 0) tmp = double_fac[2 * j - 1];
                else tmp = 1;
                res = res * C[m - 2 * i][j] % mod * C[n - i][2 * j] % mod * tmp % mod * fac[j] % mod;

                long long rem_p = p - 2 * i - 2 * j;
                long long rem_q = q;
                long long rem_n = n - i - 2 * j;
                long long rem_m = m - j - 2 * i;
                for(long long k = 0; k <= rem_p + rem_q; k++)
                {
                    if(k > rem_m || k > rem_n) break;
                    long long min_p = max(0LL, k - rem_q);
                    long long max_p = min(k, rem_p);
                    if(min_p == 0) tmp = 0;
                    else tmp = sum[k][min_p - 1];
                    long long cnt = C[rem_n][k] * C[rem_m][k] % mod * fac[k] % mod * (sum[k][max_p] - tmp) % mod;
                    ans = (ans + cnt * res % mod) % mod;
                }
            }
        }
        ans = (ans + mod - 1)  % mod;
        printf("%lld\n", ans);
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
