#include <bits/stdc++.h>
#ifdef __WINDOWS_
#include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

const int maxn = 1e5 + 5;
const int maxm = 1005;
const int mod = 1e6 + 3;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;

struct Edge
{
    int to,next;
} edge[maxn<<1];

int head[maxn], tot, top[maxn], fa[maxn], deep[maxn];
int num[maxn], p[maxn], fp[maxn], son[maxn], pos;
int ans[maxn];

void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
    pos = 1;
    memset(son,-1,sizeof(son));
}

void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void dfs1(int u,int pre,int d)
{
    deep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != pre)
        {
            dfs1(v,u,d+1);
            num[u] += num[v];
            if(son[u] == -1 || num[v] > num[son[u]])
                son[u] = v;
        }
    }
}

void getpos(int u,int sp)
{
    top[u] = sp;
    p[u] = pos++;
    fp[p[u]] = u;
    if(son[u] == -1)return;
    getpos(son[u],sp);
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != son[u] && v != fa[u])
            getpos(v,v);
    }
}

std::vector<int> avec[maxn],dvec[maxn];
void change(int u,int v,int z)
{
    int f1 = top[u],f2 = top[v];
    int tmp = 0;
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        avec[p[f1]].push_back(z);
        dvec[p[u]+1].push_back(z);
        u = fa[f1];
        f1 = top[u];
    }
    if(deep[u] > deep[v])swap(u,v);
    avec[p[u]].push_back(z);
    dvec[p[v]+1].push_back(z);
}

struct Node
{
    int l,r,Max,id;
} segTree[maxn<<2];

void push_up(int i)
{
    if(segTree[i<<1].Max < segTree[(i<<1)|1].Max)
    {
        segTree[i].Max = segTree[(i<<1)|1].Max;
        segTree[i].id = segTree[(i<<1)|1].id;
    }
    else
    {
        segTree[i].Max = segTree[i<<1].Max;
        segTree[i].id = segTree[i<<1].id;
    }
}

void build(int i,int l,int r)
{
    segTree[i].l = l;
    segTree[i].r = r;
    if(l == r)
    {
        segTree[i].id = l;
        segTree[i].Max = 0;
        return;
    }
    int mid = (l+r)/2;
    build(i<<1,l,mid);
    build((i<<1)|1,mid+1,r);
    push_up(i);
}

void update(int i,int k,int val)
{
    if(segTree[i].l == k && segTree[i].r == k)
    {
        segTree[i].Max += val;
        return;
    }
    int mid = (segTree[i].l+segTree[i].r)/2;
    if(k <= mid)update(i<<1,k,val);
    else update((i<<1)|1,k,val);
    push_up(i);
}

void solve()
{
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        if(n == 0 && m == 0)break;
        init();
        for(int i = 1; i < n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs1(1,0,0);
        getpos(1,1);
        for(int i = 1; i <= 100000; i++)
        {
            avec[i].clear();
            dvec[i].clear();
        }
        while(m--)
        {
            int u, v, z;
            scanf("%d%d%d",&u,&v,&z);
            change(u,v,z);
        }
        build(1,1,100000);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < avec[i].size(); j++)
                update(1,avec[i][j],1);
            for(int j = 0; j < dvec[i].size(); j++)
                update(1,dvec[i][j],-1);
            int u = fp[i];
            if(segTree[1].Max == 0)ans[u] = 0;
            else ans[u] = segTree[1].id;
        }
        for(int i = 1; i <= n; i++)
            printf("%d\n",ans[i]);
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
