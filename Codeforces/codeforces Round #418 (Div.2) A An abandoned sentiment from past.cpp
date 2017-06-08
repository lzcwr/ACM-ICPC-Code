#include <bits/stdc++.h>
#ifdef __WINDOWS_
	#include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
// #define lson l, m, rt << 1
// #define rson m + 1, r, rt << 1 | 1
// #define root 1, n, 1

int a[205], b[205];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < k; i++)
		scanf("%d", &b[i]);
	sort(b, b + n, greater<int>());
	int pos = 0;
	for(int i = 0; i < n; i++)
		if(a[i] == 0) a[i] = b[pos++];
	bool stat = false;
	for(int i = 0; i < n - 1; i++)
		if(a[i] > a[i + 1]) stat = true;
	sort(a, a + n);
	int len = unique(a, a + n) - a;
	if(len != n) stat = true;
	if(stat) printf("Yes\n");
	else printf("No\n");

	return 0;
}
