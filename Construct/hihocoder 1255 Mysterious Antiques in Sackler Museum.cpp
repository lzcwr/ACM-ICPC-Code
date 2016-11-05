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

struct Rect
{
    int w, h;
    Rect() {}
    Rect(int _w, int _h): w(_w), h(_h) {}
} r[5];

Rect Union(Rect a, Rect b)
{
    if(a.w == b.w) return Rect(a.w, a.h + b.h);
    else if(a.h == b.w) return Rect(a.h, a.w + b.h);
    else if(a.h == b.h) return Rect(a.h, a.w + b.w);
    else if(a.w == b.h) return Rect(a.w, a.h + b.w);
    else return Rect(-1, -1);
}

bool judge(Rect a, Rect b, Rect c)
{
    Rect tmp;
    tmp = Union( Union(a, b), c );
    if(tmp.w > 0) return true;
    tmp = Union( Union(a, c), b );
    if(tmp.w > 0) return true;
    tmp = Union( Union(b, c), a );
    if(tmp.w > 0) return true;
    return false;
}

void solve()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        for(int i = 0; i < 4; i++)
            scanf("%d%d", &r[i].w, &r[i].h);
        bool state = false;
        if( judge(r[0], r[1], r[2]) ) state = true;
        if( judge(r[0], r[1], r[3]) ) state = true;
        if( judge(r[0], r[2], r[3]) ) state = true;
        if( judge(r[1], r[2], r[3]) ) state = true;
        if(state) printf("Yes\n");
        else printf("No\n");
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
