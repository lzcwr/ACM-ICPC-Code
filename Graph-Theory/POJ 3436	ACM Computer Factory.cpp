#include <bits/stdc++.h>
#ifdef __WINDOWS_
  #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

const int maxn = 105;
const int maxm = 1e5 + 5;
const int mod = 10000;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;

int g[maxn][maxn];
int path[maxn], flow[maxn], source, dest;
int n;  // 0 ~ n including source and dest

std::queue<int> Q;
int bfs()
{
    int i, t;
    while(!Q.empty()) Q.pop();
    memset(path, -1, sizeof(path));
    path[source] = 0;
    flow[source] = inf;
    Q.push(source);
    while(!Q.empty())
    {
        t = Q.front();
        Q.pop();
        if(t == dest) break;
        for(i = 0; i <= n; i++)
        {
            if(i != source && path[i] == -1 && g[t][i])
            {
                flow[i] = flow[t] < g[t][i] ? flow[t] : g[t][i];
                Q.push(i);
                path[i] = t;
            }
        }
    }
    if(path[dest] == -1) return -1;
    return flow[dest];
}

int Edmonds_Karp()
{
    int max_flow = 0;
    int step, now, pre;
    while((step = bfs()) != -1)
    {
        max_flow += step;
        now = dest;
        while(now != source)
        {
            pre = path[now];
            g[pre][now] -= step;
            g[now][pre] += step;
            now=pre;
        }
    }
    return max_flow;
}

int backup[maxn][maxn];
int in[maxn][20];
int Line[maxn][4];

int main()
{
    int p, N;
    scanf("%d%d", &p, &N);
    memset(g, 0, sizeof(g));
    for(int i = 1; i <= N; i++)
        for(int j = 0; j < 2 * p + 1; j++)
            scanf("%d", &in[i][j]);
    for(int i = 1; i <= N; i++)
        g[2 * i - 1][2 * i] = in[i][0];
    n = 2 * N + 1;
    source = 0;
    dest = n;
    for(int i = 1; i <= N; i++)
    {
        bool flag_s = true;
        bool flag_t = true;
        for(int j = 0; j < p; j++)
        {
            if(in[i][j + 1] == 1) flag_s = false;
            if(in[i][j + 1 + p] == 0) flag_t = false;
        }
        if(flag_s) g[0][2 * i - 1] = inf;
        if(flag_t) g[2 * i][n] = inf;
        for(int j = 1; j <= N; j++)
            if(i != j)
            {
                bool flag = true;
                for(int k = 0; k < p; k++)
                    if((in[i][k + p + 1] == 0 && in[j][k + 1] == 1)||(in[i][k + p + 1] == 1 && in[j][k + 1] == 0))
                    {
                        flag=false;
                        break;
                    }
                if(flag) g[2 * i][2 * j - 1] = min(in[i][0], in[j][0]);
            }

    }
    memcpy(backup, g, sizeof(g));
    printf("%d ", Edmonds_Karp());
    int tol = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
        {
            if(g[2 * i][2 * j - 1] < backup[2 * i][2 * j - 1])
            {
                Line[tol][0] = i;
                Line[tol][1] = j;
                Line[tol][2] = backup[2 * i][2 * j - 1] - g[2 * i][2 * j - 1];
                tol++;
            }
        }
    printf("%d\n", tol);
    for(int i = 0; i < tol; i++)
        printf("%d %d %d\n", Line[i][0], Line[i][1], Line[i][2]);

    return 0;
}
