#include <bits/stdc++.h>
#ifdef __WINDOWS_
	#include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
// #define lson l, m, rt << 1
// #define rson m + 1, r, rt << 1 | 1
// #define root 1, n, 1

const int maxn = 1005;
int a[maxn], b[maxn];
int x[maxn];

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		memset(x, 0, sizeof(x));
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for(int i = 0; i < n; i++)
			scanf("%d", &b[i]);
		for(int i = 0; i < n; i++)
			x[a[i]]++;
		int p, q, q1, q2;
		for(int i = 1; i <= n; i++)
		{
			if(x[i] == 0) p = i;
			if(x[i] == 2) q = i;
		}
		bool stat = false;
		for(int i = 0; i < n; i++)
		{
			if(!stat && a[i] == q) q1 = i, stat = true;
			if(stat && a[i] == q) q2 = i;
		}
		// printf("%d %d\n", q1, q2);
		a[q1] = p; int cnt = 0;
		for(int i = 0; i < n; i++)
			if(a[i] != b[i]) cnt++;
		if(cnt == 1)
		{
			for(int i = 0; i < n; i++)
				printf("%d ", a[i]);
			printf("\n");
		}
		else
		{
			a[q1] = q; a[q2] = p;
			for(int i = 0; i < n; i++)
				printf("%d ", a[i]);
			printf("\n");
		}
	}

	return 0;
}
