#include <bits/stdc++.h>
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);

const int maxn = 80005;
const double eps = 1e-8;
const double pi = acos(-1.0);

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		if(i % 2 == 0)
			printf("I hate ");
		if(i % 2 == 1)
			printf("I love ");
		if(i != n - 1)
			printf("that ");
	}
	printf("it\n");

	return 0;
}
