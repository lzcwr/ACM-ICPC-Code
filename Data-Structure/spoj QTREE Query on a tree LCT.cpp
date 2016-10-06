#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

const int maxn = 10010;
const int maxm = 100005;
const int mod = 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int inf = 0x7fffffff;

int ch[maxn][2], pre[maxn], Max[maxn], key[maxn];
bool rt[maxn];

void push_down(int r) {}

void push_up(int r)
{
	Max[r] = max(max(Max[ch[r][false]], Max[ch[r][true]]), key[r]);
}

void Rotate(int x)
{
	int y = pre[x], kind = ch[y][true] == x;
	ch[y][kind] = ch[x][!kind];
	pre[ch[y][kind]] = y;
	pre[x] = pre[y];
	pre[y] = x;
	ch[x][!kind] = y;
	if(rt[y]) rt[y] = false, rt[x] = true;
	else ch[pre[x]][ch[pre[x]][true] == y] = x;
	push_up(y);
}

void P(int r)
{
	if(!rt[r]) P(pre[r]);
	push_down(r);
}

void Splay(int r)
{
	while(!rt[r])
	{
		int f = pre[r], ff = pre[f];
		if(rt[f]) Rotate(r);
		else if( (ch[ff][true] == f) == (ch[f][true] == r) )
			Rotate(f), Rotate(r);
		else Rotate(r), Rotate(r);
	}
	push_up(r);
}

int Access(int x)
{
	int y = 0;
	do{
		Splay(x);
		rt[ch[x][true]] = true;
		rt[ch[x][true] = y] = false;
		push_up(x);
		x = pre[y = x];
	} while(x);
	return y;
}

void lca(int &u, int &v)
{
	Access(v); v = 0;
	while(u)
	{
		Splay(u);
		if(!pre[u]) return ;
		rt[ch[u][true]] = true;
		rt[ch[u][true] = v] = false;
		push_up(u);
		u = pre[v = u];
	}
}

void change(int u, int k)
{
	Access(u);
	key[u] = k;
	push_up(u);
}

void query(int u, int v)
{
	lca(u, v);
	printf("%d\n", max(Max[v], Max[ch[u][true]]));
}

struct Edge
{
	int to, nxt;
	int val, idx;
} edge[maxn << 1];
int head[maxn], id[maxn], tot;

void addedge(int u, int v, int val, int idx)
{
	edge[tot].to = v; edge[tot].nxt = head[u];
	edge[tot].val = val; edge[tot].idx = idx;
	head[u] = tot++;
}

void dfs(int u)
{
	for(int i = head[u]; i != -1; i = edge[i].nxt)
	{
		int v = edge[i].to;
		if(pre[v] != 0) continue;
		pre[v] = u;
		id[edge[i].idx] = v;
		key[v] = edge[i].val;
		dfs(v);
	}
}

void init()
{
	tot = 0;
	memset(head, -1, sizeof(head));
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		init();
		int n;
		scanf("%d", &n);
		for(int i = 0; i <= n; i++)
		{
			pre[i] = 0;
			ch[i][false] = ch[i][true] = 0;
			rt[i] = true;
		}
		Max[0] = -inf;
		for(int i = 1; i < n; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			addedge(u, v, w, i);
			addedge(v, u, w, i);
		}
		pre[1] = -1;
		dfs(1);
		pre[1] = 0;
		char op[20];
		while(scanf("%s", op) != EOF)
		{
			if(op[0] == 'D') break;
			int a, b;
			scanf("%d%d", &a, &b);
			if(op[0] == 'C') change(id[a], b);
			else query(a, b);
		}
	}

	return 0;
}
