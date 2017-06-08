#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
// #define lson l, m, rt << 1
// #define rson m + 1, r, rt << 1 | 1
// #define root 1, n, 1

const int maxn = 1505;

char s[maxn];
int n;
int res[30][maxn], dp[maxn][maxn];

void init()
{
    for(int co = 0; co < 26; co++)
    {
        for(int left = 0; left < n; left++)
        {
            int right = left;
            for(int num = 1; num <= n; num++)
            {
                while(right < n && s[right] == 'a' + co) right++;
                if(right != n) right++;
                while(right < n && s[right] == 'a' + co) right++;
                dp[left][num] = right - left;
                if(right == n)
                {
                    for(int temp = num+1; temp <= n; temp++)
                        dp[left][temp] = dp[left][num];
                    break;
                }
            }
        }
        for(int num = 1; num <= n; num++)
        {
            int Max = 0;
            for(int left = 0; left < n; left++)
                if(Max < dp[left][num]) Max = dp[left][num]; 
            res[co][num] = Max;
        }
    }
}

int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    init();
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int num; char ch[5];
        scanf("%d%s", &num, ch);
        printf("%d\n", res[ch[0]-'a'][num]);
    }

    return 0;
}
