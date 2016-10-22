#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

const int maxn = 100005;
const int maxm = 1005;
const int mod = 10000;
const double eps = 1e-8;
const double pi = acos(-1.0);
// const int inf = std::numeric_limits<int>::max();
const int inf = 0x3f3f3f3f;

char s[1005][10];

int main()
{
    int n;
    scanf("%d", &n);
    int tmp(-1);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", s[i]);
        if(s[i][0] == s[i][1] && s[i][0] == 'O')
            tmp = i * 1000 + 1;
        if(s[i][3] == s[i][4] && s[i][3] == 'O')
            tmp = i * 1000 + 2;
    }
    if(tmp == -1)
        printf("NO\n");
    else
    {
        int row = tmp / 1000;
        int area = tmp % 1000;
        printf("YES\n");
        for(int i = 0; i < n; i++)
        {
            if(i == row)
            {
                if(area == 1)
                    s[i][0] = s[i][1] = '+';
                else
                    s[i][3] = s[i][4] = '+';
            }
            printf("%s\n", s[i]);
        }
    }

    return 0;
}
