#include <bits/stdc++.h>
#ifdef __WINDOWS_
#include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n",  clock() / (double)CLOCKS_PER_SEC);

const int maxn = 105;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int inf = 0x7f7f7f7f;
const int INF = 1 << 28;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
 
int n, m, k; 
int vis[maxn][maxn], p[5], sx, sy;
char g[maxn][maxn]; 
 
struct node 
{ 
    int x, y, step;
    node(){}
    node(int a, int b, int c): x(a), y(b), step(c) {} 
} tmp[6]; 
 
int bfs() 
{ 
    queue<node> q; 
    q.push(node(sx, sy, 0)); 
    memset(vis, 0, sizeof(vis)); 
    vis[sx][sy] = 1; 
    for(int i = 0; !q.empty(); ) 
    { 
      node temp = q.front(); 
      q.pop(); 
      for(int j = 0; j < 4; j++) 
      { 
          int xx = temp.x + dx[j]; 
          int yy = temp.y + dy[j]; 
          int step = temp.step + 1; 
          if(xx < 0 || yy < 0 || xx >= n || yy >= m || g[xx][yy] == '#' || vis[xx][yy]) continue; 
          int flag = xx == tmp[p[i]].x && yy == tmp[p[i]].y; 
          if(flag) 
          { 
              while(!q.empty()) q.pop(); 
              memset(vis, 0, sizeof(vis)); 
              if(++i == k) return step; 
          } 
          q.push(node(xx, yy, step)); 
          vis[xx][yy] = 1; 
          if(flag) break; 
      } 
    } 
 
    return -1; 
} 

void solve() 
{
    while(scanf("%d%d", &n, &m)!=EOF && n != 0) 
    { 
        for(int i = 0; i < n; i++) 
        { 
             scanf("%s", g[i]); 
             for(int j = 0; j < m; j++) 
             { 
                 if(g[i][j] == '@') 
                 { 
                    sx = i; sy = j; 
                 } 
             } 
        } 
        scanf("%d", &k); 
        int cas = 1; 
        for(int i = 0; i < k; i++) 
        { 
            scanf("%d%d", &tmp[i].x, &tmp[i].y); 
            tmp[i].x--; tmp[i].y--; 
            p[i] = i; 
            cas *= i + 1; 
        } 
 
        int ans = -1; 
        while(cas--) 
        { 
            int temp = bfs();
            if(temp > -1 && (temp < ans || ans == -1)) ans = temp; 
            next_permutation(p, p + k); 
        } 
        printf("%d\n", ans); 
    }
} 

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif

    solve();

// #ifndef ONLINE_JUDGE
//     fclose(stdin);
//     fclose(stdout);
//     system("out.txt");
// #endif

    return 0;
}
