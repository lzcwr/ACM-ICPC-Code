#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 100005;

int Hash[maxn], r[maxn], sum[maxn];

struct node
{
    int id, cnt;
    bool operator < (const node &t)const{
        return cnt < t.cnt;
    }
};

int ans[maxn][3];

int main()
{
    int n, k=0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &r[i]);
        Hash[i] = r[i];
    }

    sort(Hash, Hash + n);
    int m = unique(Hash, Hash + n) - Hash;

    memset(sum, 0, sizeof(sum));

    for(int i = 0; i < n; i++)
    {
        int id = lower_bound(Hash, Hash + m, r[i]) - Hash;
        sum[id]++;
    }

    priority_queue<node> Q;
    node p;

    for(int i = 0; i < m; i++)
    {
        if(sum[i])
        {
            p.id = i;
            p.cnt = sum[i];
            Q.push(p);
        }
    }

    node use[10];

    while(Q.size() >= 3)
    {
        for(int i = 0; i < 3; i++)
        {
            use[i] = Q.top();
            Q.pop();
            ans[k][i] = Hash[use[i].id];
            use[i].cnt -= 1;
        }
        for(int i = 0; i < 3; i++)
            if(use[i].cnt)
                Q.push(use[i]);
        k++;
    }

    printf("%d\n", k);

    for(int i = 0; i < k; i++)
    {
        sort(ans[i], ans[i] + 3);
        printf("%d %d %d\n", ans[i][2], ans[i][1], ans[i][0]);
    }

    return 0;
}
