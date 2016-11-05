#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

const int maxn = 505;
const int maxm = 100010;
const int mod = 1e6 + 3;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;

void draw_snake(int n)
{
    int x = (n + 1) >> 1;
    int y = n * (n + 1) / 2 / x;
    if(n == 2)
    {
        printf("1 1\n");
        printf("1 2 1 3\n");
        return ;
    }
    if(n == 3)
    {
        printf("2 1\n");
        printf("1 1 1 2\n");
        printf("1 3 2 3 2 2\n");
        return ;
    }

    if(n & 1)
    {
        draw_snake(n - 3);
        int row = (n - 2) >> 1;
        int col = (n - 3) * (n - 2) / 2 / row;
        int len = (n - 1) >> 1;
        for(int i = 1; i <= len; i++)
            printf("%d %d ", i, col + 1);
        for(int i = 0; i < len - 1; i++)
            printf("%d %d ", row + 1, col - i);
        printf("\n");

        for(int i = 1; i <= len; i++)
            printf("%d %d ", row + 1, i);
        for(int i = len; i >= 1; i--)
            printf("%d %d ", row + 2, i);
        printf("\n");

        for(int i = 1; i <= len + 1; i++)
            printf("%d %d ", i, col + 2);
        for(int i = 0; i < len; i++)
            printf("%d %d ", row + 2, col - i + 1);
        printf("\n");
    }
    else
    {
        draw_snake(n - 1);
        int col = n * (n - 1) / 2 / (n / 2);
        for(int i = 1; i <= n / 2; i++)
            printf("%d %d ", i, col + 1);
        for(int i = n / 2; i >= 1; i--)
            printf("%d %d ", i, col + 2);
        printf("\n");
    }
}

void solve()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        if(n == 1) 
        {
            printf("1 1\n");
            printf("1 1\n");
            continue;
        }
        int h = (n + 1) >> 1;
        int w = n * (n + 1) / 2 / h;
        printf("%d %d\n", h, w);
        draw_snake(n);
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
