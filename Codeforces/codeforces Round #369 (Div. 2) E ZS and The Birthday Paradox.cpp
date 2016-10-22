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
const int mod = 1e6 + 3;
const double eps = 1e-8;
const double pi = acos(-1.0);
// const int inf = std::numeric_limits<int>::max();
const int inf = 0x3f3f3f3f;

long long pow_mod(long long a, long long n, long long p)
{
    long long ret = 1;
    while(n)
    {
        if(n & 1) ret = ret * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ret;
}

long long inv(long long x)
{
    return pow_mod(x, mod - 2, mod);
}

int main()
{
    long long n, k;
    long long inv2 = inv(2);
    scanf("%lld%lld", &n, &k);
    if(n <= 62 && (1LL << n) < k)
        printf("1 1\n");
    else
    {
        long long cnt2 = n;
        for(int i = 1; i < 62; i++)
            cnt2 += (k - 1) / (1LL << i);
        long long aaa = 1;
        if(k < mod)
        {
            for(long long i = 1; i <= k; i++)
                aaa = aaa * ( pow_mod(2, n, mod) - i + mod + 1 ) % mod;
            aaa = aaa * pow_mod(inv2, cnt2, mod) % mod;
        }
        else aaa = 0;
        long long bbb = pow_mod( pow_mod(2, n, mod), k, mod ) * pow_mod(inv2, cnt2, mod) % mod;

        printf("%lld %lld\n", (bbb - aaa + mod) % mod, bbb);
    }

    return 0;
}
