#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt  <<  1
#define rson m + 1, r, rt  <<  1 | 1
#define root 1, n, 1

const int maxn = 1005;
const int maxm = 1e5 + 5;
const int mod = 10000;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;

int main()
{
    int t;
    scanf("%d", &t);
    int cas(0);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        printf("Case %d:\n", ++cas);
        char s[20];
        int sum(0);
        for(int i = 0; i < n; i++)
        {
            scanf("%s", s);
            if(s[0] == 'd')
            {
                int tmp;
                scanf("%d", &tmp);
                sum += tmp;
            }
            if(s[0]  == 'r')
                printf("%d\n", sum);
        }
    }

    return 0;
}
