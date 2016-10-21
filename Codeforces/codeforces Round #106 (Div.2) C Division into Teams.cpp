#include <bits/stdc++.h>
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);

const int maxn = 1e5 + 5;

int n;
struct node
{
	int value, id;
} a[maxn];
bool cmp(node a, node b)
{
	return a.value < b.value;
}
vector<int> ans_x, ans_y;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i].value);
		a[i].id = i + 1;
	}
	sort(a, a + n, cmp);
	int sum_x(0), sum_y(0);
	for(int i = 0; i < n - 1; i++)
	{
		if (i & 1)
		{
			ans_x.push_back(a[i].id);
			sum_x += a[i].value;
		}
		else
		{
			ans_y.push_back(a[i].id);
			sum_y += a[i].value;
		}
	}
	if (sum_x < sum_y) ans_x.push_back(a[n - 1].id);
	else ans_y.push_back(a[n - 1].id);

	int sz_y = ans_y.size();
	printf("%d\n", sz_y);
	for(int i = 0; i < sz_y; i++)
		printf("%d%c", ans_y[i], i == sz_y - 1 ? '\n' : ' ');

	int sz_x = ans_x.size();
	printf("%d\n", sz_x);
	for(int i = 0; i < sz_x; i++)
		printf("%d%c", ans_x[i], i == sz_x - 1 ? '\n' : ' ');

	return 0;
}
