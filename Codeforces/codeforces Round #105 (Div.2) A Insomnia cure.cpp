#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 5;
bool vis[maxn];

int main()
{
	int a[5], d, cnt(0);
	scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &d);
	memset(vis, false, sizeof(vis));
	for(int i = 1; i <= d; i ++)
		for(int j = 0; j < 4; j++)
			if((i % a[j] == 0) && !vis[i])
			{
				vis[i] = true;
				cnt ++;
			}
	printf("%d\n", cnt);
    
	return 0;
}
