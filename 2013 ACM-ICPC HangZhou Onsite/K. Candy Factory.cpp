#include <bits/stdc++.h>
#ifdef __WINDOWS_
#include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n",  clock() / (double)CLOCKS_PER_SEC);

const int maxn = 605;
const int maxm = 100005;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int inf = 0x7f7f7f7f;
const int INF = 1 << 28;

struct Edge
{
    int to, nxt, cap, flow, cost;
} edge[maxm];

int head[maxn], tol, pre[maxn], dis[maxn];
bool vis[maxn];
int N;

void init(int n)
{
    N = n;
    tol = 0;
    memset(head, -1, sizeof(head));
}

void addedge(int u, int v, int cap, int cost)
{
    edge[tol].to = v; edge[tol].cap = cap; edge[tol].cost = cost;
    edge[tol].flow = 0; edge[tol].nxt = head[u]; head[u] = tol++;
    edge[tol].to = u; edge[tol].cap = 0; edge[tol].cost = -cost;
    edge[tol].flow = 0; edge[tol].nxt = head[v]; head[v] = tol++;
}

bool spfa(int s, int t)
{
    std::queue<int> Q;
    for(int i = 0; i < N; i++)
    {
        dis[i] = inf;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0; vis[s] = true;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();
        vis[u] = false;
        for(int i = head[u]; i != -1; i = edge[i].nxt)
        {
            int v = edge[i].to;
            if(edge[i].cap > edge[i].flow && dis[v] > dis[u] + edge[i].cost)
            {
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i;
                if(!vis[v])
                {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
    }
    if(pre[t] == -1) return false;
    else return true;
}

std::pair<int, int> min_cost_max_flow(int s, int t)
{
    int flow = 0, cost = 0;
    while(spfa(s, t))
    {
        int Min = inf;
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
            Min = min(Min, edge[i].cap - edge[i].flow);
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cost += edge[i].cost * Min;
        }
        flow += Min;
    }
    return make_pair(cost, flow);
}

int s[maxn], t[maxn], c[maxn][maxn], d[maxn][maxn], e[maxn][maxn], f[maxn][maxn];

void solve()
{
    int NN, MM, KK;
    while(scanf("%d%d%d", &NN, &MM, &KK) != EOF)
    {
        if(NN + MM + KK == 0) break;
        for(int i = 0; i < NN; i++)
            scanf("%d%d", &s[i], &t[i]);
        for(int i = 0; i < NN; i++)
        for(int j = 0; j < MM; j++)
            scanf("%d", &c[i][j]);
        for(int i = 0; i < NN; i++)
        for(int j = 0; j < MM; j++)
            scanf("%d", &d[i][j]);
        for(int i = 0; i < NN; i++)
        for(int j = 0; j < NN; j++)
            scanf("%d", &e[i][j]);
        for(int i = 0; i < NN; i++)
        for(int j = 0; j < NN; j++)
            scanf("%d", &f[i][j]);

        init(3 * NN + MM + 2);
        int S = 3 * NN + MM, T = 3 * NN + MM + 1;
        for(int i = 0; i < NN; i++)
            addedge(S, i, 1, 0);
        for(int i = 0; i < NN; i++)
            addedge(i + NN, i + 2 * NN, 1, 0);
        for(int i = 0; i < NN; i++)
            addedge(i + 2 * NN, T, 1, 0);
        for(int i = 0; i < MM; i++)
            addedge(S, i + 3 * NN, 1, 0);

        for(int i = 0; i < NN; i++)
            for(int j = 0; j <NN; j++)
            {
                if(i == j) continue;
                if(t[i] + e[i][j] >= t[j]) continue;
                int tmp = f[i][j] + max(0, t[i] + e[i][j] - s[j]) * KK;
                addedge(i, j + 2 * NN, 1, tmp);
            }
        for(int j = 0; j < MM; j++)
            for(int i = 0; i < NN; i++)
            {
                if(c[i][j] >= t[i]) continue;
                int tmp = d[i][j] + max(0, c[i][j] - s[i]) * KK;
                addedge(j + 3 * NN, i + NN, 1, tmp);
            }
        std::pair<int, int> ans = min_cost_max_flow(S, T);
        if(ans.second == NN) printf("%d\n", ans.first);
        else printf("-1\n");
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
