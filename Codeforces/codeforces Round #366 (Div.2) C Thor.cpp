#include <bits/stdc++.h>
using namespace std; 

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);

const int maxn = 3e5 + 5;

int n, Q, aaa[maxn] = {0};
int lowbit(int i)
{
    return i & (-i);
}
int insert(int k, int d)
{
    for(int i = k; i <= n; i += lowbit(i))
        aaa[i] += d;
}
int query(int k)
{
    int res = 0;
    for(int i = k; i > 0; i -= lowbit(i))
        res += aaa[i];
    return res;
}
int cnt[maxn] = {0};
int main()
{
    scanf("%d%d", &n, &Q);
    queue<int> q;
    int pos = 1;
    int op, k;
    while(Q--)
    {
        scanf("%d%d", &op, &k);
        if(op == 1)
        {
            insert(k, 1);
            q.push(k);
        }
        else if(op == 2)
        {
            int t = query(k)-query(k-1);
            insert(k, -t);
            cnt[k] += t;
        }
        else
        {
            while(pos <= k)
            {
                int p = q.front(); q.pop();
                if(cnt[p] != 0)
                    cnt[p]--;
                else
                    insert(p, -1);
                pos++;
            }
        }
        printf("%d\n", query(n));
    }

    return 0;
}
