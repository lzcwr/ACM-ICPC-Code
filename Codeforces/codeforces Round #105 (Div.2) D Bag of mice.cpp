#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1005;
double dp[maxn][maxn];

int main()
{
	int w, b;
	scanf("%d%d", &w, &b);

	dp[0][0] = 0;
	for(int i = 1; i <= b; i ++)
		dp[0][i] = 0;
	for(int i = 1; i <= w; i++)
		dp[i][0] = 1.0;
	for(int i = 1; i <= w; i++)
	{
		for(int j = 1; j <= b; j++)
		{
			dp[i][j] += (double) i / (i + j);
			if(j >= 2)
				dp[i][j] += (double) j / (i + j) * (double) (j - 1) / (i + j - 1) * (double) i / (i + j - 2) * dp[i - 1][j - 2];
			if(j >= 3)
				dp[i][j] += (double) j / (i + j) * (double) (j - 1) / (i + j - 1) * (double) (j - 2) / (i + j - 2) * dp[i][j - 3];
		}
	}
	printf("%.9f\n", dp[w][b]);
    
	return 0;
}
