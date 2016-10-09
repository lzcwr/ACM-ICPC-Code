#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt  <<  1
#define rson m + 1, r, rt  <<  1 | 1
#define root 1, n, 1

const int maxn = 505;
const int maxm = 1e5 + 5;
const int mod = 10000;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;

int node, source, dest, tot;
int head[maxn], to[maxm], nxt[maxm], flow[maxm], capa[maxm];
int dist[maxn], Q[maxn], work[maxn];

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

long long dinic()
{
    long long ret(0);
    while(bfs())
    {
        for(long long i = 0; i < node; i++)
            work[i] = head[i];
        while(true)
        {
            long long delta = dfs(source, inf);
            if(delta == 0) break;
            ret += delta;
        }
    }
    return ret;
}

int main()
{
    int N, F, D;
    scanf("%d%d%d", &N, &F, &D);
    init(F + 2 * N + D + 2, 0, F + 2 * N + D + 1);
    for(int i = 1; i <= F; i++)
        addedge(source, i, 1, 0); //SOURCE->FOOD
    for(int i = F + 2 * N + 1; i <= F + 2 * N + D; i++)
        addedge(i, dest, 1, 0); // DRINK->DEST
    for(int i = 1; i <= N; i++) // COW
    {
        addedge(F + i, F + N + i, 1, 0);
        int a, b;
        scanf("%d%d", &a, &b);
        int tmp;
        while(a--) // FOOD
        {
            scanf("%d", &tmp);
            addedge(tmp, F + i, 1, 0); // FOOD->COW
        }
        while(b--) // DRINK
        {
            scanf("%d", &tmp);
            addedge(F + N + i, 2 * N + F + tmp, 1, 0); // COW->DRINK
        }
    }
    printf("%d\n", dinic());

    return 0;
}
