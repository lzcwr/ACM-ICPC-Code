#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

const int maxn = 2e5 + 5;
const int maxm = 1005;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
// const int inf = std::numeric_limits<int>::max();
const int inf = 0x3f3f3f3f;

struct Point
{
    double x, y;
    Point() {}
    Point(double _x, double _y): x(_x), y(_y) {}
    Point operator - (const Point &b) const
    {
        return Point(x - b.x, y - b.y);
    }
    double operator * (const Point &b) const
    {
        return (x * b.x + y * b.y);
    }
    double length()
    {
        return sqrt(x * x + y * y);
    }
    void input()
    {
        scanf("%lf%lf", &x, &y);
    }
} O, A, B;

double dist(Point A, Point B)
{
    return (A - B).length();
}

void solve()
{
    int t, cas(0);
    scanf("%d", &t);
    while(t--)
    {
        O.input();
        A.input();
        B.input();
        double OA = dist(O, A);
        double AB = dist(A, B);
        double ang_A = acos( (OA * OA * 2 - AB * AB) / (2 * OA * OA) );
        printf("Case %d: %.12f\n", ++cas, OA * ang_A);
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
