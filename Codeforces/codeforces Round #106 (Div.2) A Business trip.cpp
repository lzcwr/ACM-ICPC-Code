#include <bits/stdc++.h>
using namespace std;
#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC) 

int main()
{
	int k, a[15];
	int sum(0), ans(-1);
	scanf("%d", &k);
	for (int i = 0; i < 12; i++)
		scanf("%d", &a[i]);
	sort(a, a + 12, greater<int>());
	if (k == 0)
	{
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < 12; i++)
	{
		sum += a[i];
		if (sum >= k)
		{
			ans = i + 1;
			break;
		}
	}
	printf("%d\n", ans); 
	return 0;
}
