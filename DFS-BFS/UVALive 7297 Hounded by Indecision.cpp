#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

const int maxn = 205;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int inf = 0x7f7f7f7f;

int step[maxn][maxn], vis[maxn][maxn];
char mp[maxn][maxn];
int w, h;
int dx[] = {1, -1, 0,  0};
int dy[] = {0,  0, 1, -1};

struct Node
{
    int x, y, lim, step;
    Node()
    {
        lim = inf; step = inf;
    }
} st;

std::queue<Node> q;

struct Point
{
    int x, y;
    Point() {}
    Point(int _x, int _y): x(_x), y(_y) {}
} now, nxt;

std::queue<Point> que;

bool judge(int x, int y)
{
    return (x >= 0 && x <= h && y >= 0 && y < w && mp[x][y] != 'X');
}

void bfs_police(int px, int py)
{
    memset(vis, false, sizeof(vis));
    vis[px][py] = true;
    step[px][py] = 0;
    now.x = px; now.y = py;
    while(!que.empty()) que.pop();
    que.push(now);
    while(!que.empty())
    {
        now = que.front();
        que.pop();
        for(int i = 0; i < 4; i++)
        {
            nxt.x = now.x + dx[i];
            nxt.y = now.y + dy[i];
            if(judge(nxt.x, nxt.y) && !vis[nxt.x][nxt.y])
            {
                step[nxt.x][nxt.y] = step[now.x][now.y] + 1;
                vis[nxt.x][nxt.y] = true;
                que.push(nxt);
            }
        }
    }
}

bool bfs_thief(Node st)
{
    memset(vis, false, sizeof(vis));
    st.step = 0;
    st.lim = (step[st.x][st.y] - st.step) + step[st.x][st.y];
    while(!q.empty()) q.pop();
    q.push(st);;
    vis[st.x][st.y] = st.lim;

    while(!q.empty())
    {
        Node now = q.front();
        q.pop();
        if(mp[now.x][now.y] == 'E') return true;
        for(int i = 0; i < 4; i++)
        {
            Node nxt = now;
            nxt.x += dx[i];
            nxt.y += dy[i];
            nxt.step++;
            if(judge(nxt.x, nxt.y))
            {
                int lim = step[nxt.x][nxt.y] + (step[nxt.x][nxt.y] - nxt.step);
                if(lim < nxt.lim) nxt.lim = lim;
                if(nxt.step < step[nxt.x][nxt.y] && nxt.step < nxt.lim && (!vis[nxt.x][nxt.y] || nxt.lim > vis[nxt.x][nxt.y]))
                {
                    vis[nxt.x][nxt.y] = lim;
                    q.push(nxt);
                }
            }
        }
    }
    return false;
}

void solve()
{
    while(scanf("%d%d", &w, &h) != EOF)
    {
        if(w < 3 || h < 3) break;
        int px, py;
        getchar();
        for(int i = 0; i < h; i++)
        {
            gets(mp[i]);
            int len = strlen(mp[i]);
            for(int j = 0; j < len; j++)
            {
                if(mp[i][j] == 'K')
                {
                    px = i; py = j;
                }
                else if (mp[i][j] == 'T')
                {
                    st.x = i; st.y = j;
                }
            }
        }

        bfs_police(px, py);
        if(bfs_thief(st)) printf("KEEP IT\n");
        else printf("DROP IT\n");
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
