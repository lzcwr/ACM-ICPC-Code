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
const int inf = 0x3f3f3f3f;

int a[5];

bool in_range(int x)
{
    return (x <= 1000000 && x > 0);
}

bool is_AP(int a[], int d)
{
    if(a[2] - a[1] != d) return false;
    if(a[3] - a[2] != d) return false;
    if(a[4] - a[3] != d) return false;
    return true;
}

bool is_GP(int a[], int q)
{
    if(a[2] != a[1] * q) return false;
    if(a[3] != a[2] * q) return false;
    if(a[4] != a[3] * q) return false;
    return true;
}

void solve()
{
    while(scanf("%d%d%d%d", &a[1], &a[2], &a[3], &a[4]))
    {
        if(a[1] == -1 && a[2] == -1 && a[3] == -1 && a[4] == -1) break;
        if(a[1] ==  0 || a[2] ==  0 || a[3] ==  0 || a[4] ==  0)
        {
            printf("-1\n");
            continue;
        }

        int pos;
        for(int i = 1; i <= 4; i++)
            if(a[i] == -1) pos = i;

        if(pos == 1)
        {
            a[0] = a[3] - a[2];
            a[1] = a[2] - a[0];
            if(is_AP(a, a[0]) && in_range(a[pos]))
            {
                printf("%d\n", a[pos]);
                continue;
            }

            a[0] = a[3] / a[2];
            a[1] = a[2] / a[0];
            if(is_GP(a, a[0]) && in_range(a[pos]))
            {
                printf("%d\n", a[pos]);
                continue;
            }
            printf("-1\n");
        }

        if(pos == 2)
        {
            a[0] = a[4] - a[3];
            a[2] = a[1] + a[0];
            if(is_AP(a, a[0]) && in_range(a[pos]))
            {
                printf("%d\n", a[pos]);
                continue;
            }

            a[0] = a[4] / a[3];
            a[2] = a[1] * a[0];
            if(is_GP(a, a[0]) && in_range(a[pos]))
            {
                printf("%d\n", a[pos]);
                continue;
            }
            printf("-1\n");
        }

        if(pos == 3)
        {
            a[0] = a[2] - a[1];
            a[3] = a[2] + a[0];
            if(is_AP(a, a[0]) && in_range(a[pos]))
            {
                printf("%d\n", a[pos]);
                continue;
            }

            a[0] = a[2] / a[1];
            a[3] = a[2] * a[0];
            if(is_GP(a, a[0]) && in_range(a[pos]))
            {
                printf("%d\n", a[pos]);
                continue;
            }
            printf("-1\n");
        }

        if(pos == 4)
        {
            a[0] = a[2] - a[1];
            a[4] = a[3] + a[0];
            if(is_AP(a, a[0]) && in_range(a[pos]))
            {
                printf("%d\n", a[pos]);
                continue;
            }

            a[0] = a[2] / a[1];
            a[4] = a[3] * a[0];
            if(is_GP(a, a[0]) && in_range(a[pos]))
            {
                printf("%d\n", a[pos]);
                continue;
            }
            printf("-1\n");
        }
    }
}

int main()
{
#ifndef ONLINE_in_range
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    solve();

#ifndef ONLINE_in_range
    fclose(stdin);
    fclose(stdout);
    system("out.txt");
#endif

    return 0;
}
