#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

const int maxn = 100005;
const int maxm = 1005;
const int mod = 10000;
const double eps = 1e-8;
const double pi = acos(-1.0);
// const int inf = std::numeric_limits<int>::max();
const int inf = 0x3f3f3f3f;

int dp_max[maxn][20];

void initRMQ(int n, int b[])
{
    for(int i = 1; i <= n; i++)
        dp_max[i][0] = b[i];
    for(int j = 1; j < log( (double)(n + 1) ) / log(2.0); j++)
        for(int i = 1; i + (1 << j) - 1 <= n; i++)
            dp_max[i][j] = max(dp_max[i][j - 1], dp_max[i + (1 << (j - 1))][j - 1]);
}

int RMQ_MAX(int x, int y)
{
    int k = (int)( log( (double)(y - x + 1) ) / log(2.0) );
    return max(dp_max[x][k], dp_max[y - (1 << k) + 1][k]);
}

int Left[maxn], Right[maxn], cnt[maxn], len[maxn], tot;

void init(int n)
{
    tot = 1;
    Left[1] = cnt[1] = len[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(a[i] == a[i - 1]) cnt[tot]++;
        else
        {
            Right[tot++] = i - 1;
            Left[tot] = i;
            cnt[tot] = 1;
        }
        len[i] = tot;
    }
    Right[tot] = n;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, q;
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0) break;
        scanf("%d", &q);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        init(n);
        initRMQ(tot, cnt);
        while(q--)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            int L = len[l], R = len[r];
            if(L == R)
                printf("%d\n", r - l + 1);
            else if(L == R - 1)
                printf( "%d\n", max(Right[L] - l + 1, r - Left[R] + 1) );
            else
            {
                int ans = max(Right[L] - l + 1, r - Left[R] + 1);
                ans = max(ans, RMQ_MAX(L + 1, R - 1));
                printf("%d\n", ans);
            }
        }
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("out.txt");
#endif

    return 0;
}
