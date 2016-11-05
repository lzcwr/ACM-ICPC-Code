#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

const int maxn = 2005;
const int maxm = 100010;
const int mod = 1e6 + 3;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;

int node, source, dest, tot;
int head[maxn], to[maxm], nxt[maxm], flow[maxm];
int dist[maxn], Q[maxn], work[maxn], capa[maxm];

void init(int _node, int _source, int _dest)
{
    node = _node;
    source = _source;
    dest = _dest;
    memset(head, -1, sizeof(head));
    tot = 0;
}

void addedge(int u, int v, int _capa, int _capa_2)
{
    to[tot] = v; capa[tot] = _capa; flow[tot] = 0; nxt[tot] = head[u]; head[u] = tot++;
    to[tot] = u; capa[tot] = _capa_2; flow[tot] = 0; nxt[tot] = head[v]; head[v] = tot++;
}

bool bfs()
{
    memset(dist, -1, sizeof(dist));
    dist[source] = 0;
    int sizeQ = 0;
    Q[sizeQ++] = source;
    for(int _capa = 0; _capa < sizeQ; _capa++)
    {
        for(int k = Q[_capa], i = head[k]; i >= 0; i = nxt[i])
        {
            if(flow[i] < capa[i] && dist[to[i]] < 0)
            {
                dist[to[i]] = dist[k] + 1;
                Q[sizeQ++] = to[i];
            }
        }
    }
    return dist[dest] >= 0;
}

int dfs(int x, int exp)
{
    if(x == dest) return exp;
    for(int &i = work[x]; i >= 0; i = nxt[i])
    {
        int v = to[i], tmp;
        if(flow[i] < capa[i] && dist[v] == dist[x] + 1 && (tmp = dfs(v, min(exp, capa[i] - flow[i]))) > 0)
        {
            flow[i] += tmp;
            flow[i^1] -= tmp;
            return tmp;
        }
    }
    return 0;
}

int dinic()
{
    int ret(0);
    while(bfs())
    {
        for(int i = 0; i < node; i++)
            work[i] = head[i];
        while(true)
        {
            int delta = dfs(source, inf);
            if(delta == 0) break;
            ret += delta;
        }
    }
    return ret;
}

void solve()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m, S;
        scanf("%d%d%d", &n, &m, &S);
        init(2 * n + 2, 0, 2 * n + 1);
        while(m--)
        {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            addedge(n + u, v, c, 0);
        }
        for(int i = 1; i <= n; i++)
        {
            int c;
            scanf("%d", &c);
            addedge(source, i, c, 0);
        }
        for(int i = 1; i <= n; i++)
        {
            int c;
            scanf("%d", &c);
            addedge(i, n + i, c, 0);
        }
        addedge(n + S, dest, inf, 0);
        printf("%d\n", dinic());
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    solve();

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("out.txt");
#endif

    return 0;
}
