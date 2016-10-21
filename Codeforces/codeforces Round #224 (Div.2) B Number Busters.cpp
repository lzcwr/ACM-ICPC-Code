#include <bits/stdc++.h>
// #include <windows.h>
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

const int maxn = 10005;
const int maxm = 1005;
const int mod = 10000;
const double eps = 1e-8;
const double pi = acos( -1.0);
const int inf = std::numeric_limits<int>::max();

long long a, b, c, w, x;

bool judge(long long r)
{
	long long n = (r * x - b) / w;
	if((r * x - b) % w) n++;
	return (r - n >= c - a);
}

int main()
{
	scanf("%lld%lld%lld%lld%lld", &a, &b, &w, &x, &c);
	if(c <= a) printf("0\n");
	else
	{
		long long L = -10, R = 2e12;
		while(R - L > 1)
		{
			long long m = L + R >> 1;
			if(judge(m)) R = m;
			else L = m;
		}
		printf("%lld\n", R);
	}
	
	return 0;
}
