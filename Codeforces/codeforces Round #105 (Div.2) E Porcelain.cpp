#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 105;
int sum[maxn], max_value[maxn], dp[10005];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		int num;
		scanf("%d", &num);
		for(int j = 1; j <= num; j++)
		{
			int in;
			scanf("%d", &in);
			sum[j] = sum[j - 1] + in;
		}
		memset(max_value, 0, sizeof(max_value));
		for(int j = 0; j <= num; j++)
			for(int k = 0; k <= j; k++)
				max_value[j] = max(max_value[j], sum[k] + sum[num] - sum[num + k - j]);
		for(int j = m; j >= 1; j--)
			for(int k = 1; k <= min(j, num); k ++)
				dp[j] = max(dp[j], dp[j - k] + max_value[k]);
	}
	printf("%d\n", dp[m]);
    
	return 0;
}
