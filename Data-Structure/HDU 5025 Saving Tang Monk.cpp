#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N = 110;
const int INF = 1e9;

struct P
{
    int r, c;
    P() {}
    P(int _r, int _c) {r = _r; c = _c;}
}Start, End;

int n, m, dp[N][N][10];
char maze[N][N];
int rm[4] = {0, 0, -1, 1};
int cm[4] = {-1, 1, 0, 0};
queue<P> q;
bool flag[N][N];
void spfa()
{
    memset(flag, false, sizeof(flag));
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    for(int s = 0; s <= m; s++)
        dp[i][j][s] = INF;
    q.push(Start);
    dp[Start.r][Start.c][0] = 0;
    flag[Start.r][Start.c]=true;

    while(!q.empty())
    {
        P p = q.front(); q.pop(); flag[p.r][p.c] = false;
        for(int i = 0; i < 4; i++)
        {
            int nr = p.r + rm[i];
            int nc = p.c + cm[i];
            if(maze[nr][nc] == '#') continue;

            for(int s = 0; s <= m; s++)
                if(dp[nr][nc][s] > dp[p.r][p.c][s]+1)
                {
                    dp[nr][nc][s] = dp[p.r][p.c][s]+1;
                    if(!flag[nr][nc])
                        q.push(P(nr,nc)), flag[nr][nc] = true;
                }

            if('1' <= maze[nr][nc] && maze[nr][nc] <= '9')
            {
                int num = maze[nr][nc] - '0';
                if(dp[nr][nc][num] > dp[nr][nc][num-1])
                {
                    dp[nr][nc][num] = dp[nr][nc][num-1];
                    if(!flag[nr][nc])
                        q.push(P(nr,nc)), flag[nr][nc] = true;
                }
            }
        }
    }
}

vector<P> snake;
int solve()
{
    int res = INF;
    for(int s = 0; s < (1<<snake.size()); s++)
    {
        int cnt = 0;
        for(int i = 0; i < snake.size(); i++)
        {
            P p = snake[i];
            if(s & (1<<i))
                maze[p.r][p.c] = '.', cnt++;
            else
                maze[p.r][p.c] = '#';
        }
        spfa();
        res = min(res, dp[End.r][End.c][m]+cnt);
    }
    return res;
}

int main()
{
    while(scanf("%d%d", &n, &m) && n != 0)
    {
        memset(maze, '#', sizeof(maze));
        for(int i = 1; i <= n; i++)
            scanf("%s", maze[i] + 1);
        for(int i = 1; i <= n; i++)
            maze[i][n+1] = '#';

        snake.clear();
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(maze[i][j] == 'K')
                Start = P(i,j);
            if(maze[i][j] == 'T')
                End = P(i,j);
            if(maze[i][j] == 'S')
                snake.push_back(P(i,j));
        }

        int res = solve();

        if(res == INF)
            printf("impossible\n");
        else
            printf("%d\n", res);
    }
    return 0;
}
