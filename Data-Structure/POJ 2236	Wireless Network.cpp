#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt  <<  1
#define rson m + 1, r, rt  <<  1 | 1
#define root 1, n, 1

const int maxn = 1010;
const int maxm = 1e5 + 5;
const int mod = 10000;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;

int fa[maxn];
int find(int x)
{
    if(fa[x] == -1) return x;
    return fa[x] = find(fa[x]);
}

void link(int u, int v)
{
    int t1 = find(u), t2 = find(v);
    if(t1 != t2) fa[t1] = t2;
}

struct Node
{
    double x, y;
} node[maxn];

double dis(Node a, Node b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool g[maxn][maxn], used[maxn];
int main()
{
    int n, d;
    memset(g, false, sizeof(g));
    memset(used, false, sizeof(used));
    memset(fa, -1, sizeof(fa));
    scanf("%d%d", &n, &d);
    for(int i = 1; i <= n; i++)
        scanf("%lf%lf", &node[i].x, &node[i].y);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(dis(node[i], node[j]) < d + eps)
                g[i][j] = true;
    char op[5];
    int u, v;
    while(scanf("%s", op) != EOF)
    {
        if(op[0] == 'O')
        {
            int tmp;
            scanf("%d", &tmp);
            if(!used[tmp])
            {
                for(int i = 1; i <= n; i++)
                    if(used[i] && g[tmp][i])
                        link(tmp, i);
                used[tmp] = true;
            }
        }
        if(op[0] == 'S')
        {
            scanf("%d%d", &u, &v);
            if(find(u) == find(v))
                printf("SUCCESS\n");
            else printf("FAIL\n");
        }
    }

    return 0;
}
