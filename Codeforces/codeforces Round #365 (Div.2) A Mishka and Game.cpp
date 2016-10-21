#include <bits/stdc++.h>
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);

int main()
{
	int n;
	int cnt1(0), cnt2(0);
	scanf("%d", &n);
	while(n--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(a > b) cnt1++;
		if(b > a) cnt2++;
	}
	if(cnt1 > cnt2) printf("Mishka\n");
	if(cnt2 > cnt1) printf("Chris\n");
	if(cnt1 == cnt2) printf("Friendship is magic!^^\n");

	return 0;
}
