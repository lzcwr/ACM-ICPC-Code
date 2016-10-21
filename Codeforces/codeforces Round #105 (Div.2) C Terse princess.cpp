#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 105;

int ans[maxn];

int main()
{
	int a, b, n;
	scanf("%d%d%d", &n, &a, &b);
	ans[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(b)
		{
			ans[i] = 1 << (i - 1);
			b--;
		}
		else if(a && i > 2)
		{
			ans[i] = ans[i - 1] + 1;
			a--;
		}
		else ans[i] = ans[i - 1]; 
	}
	if(a || b)
		printf("-1\n");
	else 
		for(int i = 1; i <= n; i++)
			printf("%d%c", ans[i], i == n ? '\n' : ' ');

	return 0;
}
