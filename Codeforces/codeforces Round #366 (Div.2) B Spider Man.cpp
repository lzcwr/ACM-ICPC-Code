#include <bits/stdc++.h>
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);

const int maxn = 100005;
const double eps = 1e-8;
const double pi = acos(-1.0);

long long a[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	long long sum(0);
	for(int i = 0; i < n; i++)
	{
		scanf("%I64d", &a[i]);
		sum += (a[i] - 1);
		if(sum % 2 == 0) printf("2\n");
		if(sum % 2 == 1) printf("1\n");
	}

	return 0;
}
