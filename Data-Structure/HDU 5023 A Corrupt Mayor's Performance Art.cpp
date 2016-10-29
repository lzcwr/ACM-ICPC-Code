#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

const int maxn = 1e6 + 5;
const int maxm = 1005;
const int mod = 1e6 + 3;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;

struct Node
{
    int l, r;
    long long x, lz;
    Node() {}
    Node(int a, int b, long long c, long long d)
    {
        l = a; r = b; x = c; lz = d;
    }
} a[maxn << 2];

long long ans, b[45];

void push_down(int rt)
{
    if(a[rt].l == a[rt].r) return ;
    if(a[rt].lz == 0) return ;

    a[rt << 1].lz = a[rt << 1].x = a[rt].lz;
    a[rt << 1 | 1].lz = a[rt << 1 | 1].x = a[rt].lz;
    a[rt].lz = 0;
}

void build(int l, int r, int rt)
{
    a[rt] = Node(l, r, 2, 0);
    if(l == r) return ;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}

void update(int l, int r, int rt, int op)
{
    if(a[rt].l == l && a[rt].r == r)
    {
        a[rt].lz = b[op];
        a[rt].x = b[op];
        return ;
    }
    push_down(rt);
    int m = (a[rt].l + a[rt].r) >> 1;
    if(r <= m) update(l, r, rt << 1, op);
    else if(l > m) update(l, r, rt << 1 | 1, op);
    else
    {
        update(lson, op);
        update(rson, op);
    }
    if(a[rt << 1].x == a[rt << 1 | 1].x)
        a[rt].x = a[rt << 1].x;
    else a[rt].x = -1;
}

void query(int l, int r, int rt)
{
    if(a[rt].x != -1)
    {
        ans |= a[rt].x;
        return ;
    }
    int m = (a[rt].l + a[rt].r) >> 1;
    push_down(rt);
    if(r <= m) query(l, r, rt << 1);
    else if(l > m) query(l, r, rt << 1 | 1);
    else
    {
        query(lson);
        query(rson);
    }
}

void init()
{
    b[1] = 1;
    for(int i = 2; i <= 30; i++)
        b[i] = b[i - 1] * 2;
}

void solve()
{
    init();
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        if(m == 0 && n == 0) break;
        build(root);
        while(m--)
        {
            char op[5];
            scanf("%s", op);
            int l, r;
            scanf("%d%d", &l, &r);
            if(op[0] == 'P')
            {
                int x;
                scanf("%d", &x);
                update(l, r, 1, x);
            }
            if(op[0] == 'Q')
            {
                ans = 0;
                query(l, r, 1);
                int first = 1, x;
                for(int i = 1; i <= 30; i++)
                {
                    if(ans & 1)
                    {
                        if(first == 0) printf(" ");
                        first = 0;
                        printf("%d", i);
                    }
                    ans /= 2;
                }
                printf("\n");
            }
        }
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
