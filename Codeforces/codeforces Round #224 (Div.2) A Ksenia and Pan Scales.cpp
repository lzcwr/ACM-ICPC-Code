#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
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

char a[maxn], b[maxn];

int main()
{
	scanf("%s%s", a, b);
	int lena = strlen(a), lenb = strlen(b);
	int l(0), r(0);
	for(int i = 0; i < lena; i++)
	{
		if(a[i] == '|') break;
		l++;
	}
	r = lena - l - 1;
	
	int tmp = abs(l - r);
	if(tmp > lenb)
		printf("Impossible\n");
	else if((lenb - tmp) & 1)
		printf("Impossible\n");
	else
	{
		int sum = l + r + lenb;
		for(int i = 0; i < l; i++)
			printf("%c", a[i]);
		for(int i = 0; i < sum / 2 - l; i++)
			printf("%c", b[i]);
		printf("%c", a[l]);
		for(int i = sum / 2 - l; i < lenb; i++)
			printf("%c", b[i]);
		for(int i = l + 1; i < lena; i++)
			printf("%c", a[i]);
		printf("\n");
	}
	
	return 0;
}
