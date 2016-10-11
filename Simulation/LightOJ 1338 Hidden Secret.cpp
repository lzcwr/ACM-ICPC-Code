#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt  <<  1
#define rson m + 1, r, rt  <<  1 | 1
#define root 1, n, 1

const int maxn = 200005;
const int maxm = 1e5 + 5;
const int mod = 10000;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    int cas(0);
    while(t--)
    {
        bool state = true;
        int a[26], cnt1(0), cnt2(0);
        char ch;
        memset(a, 0, sizeof(a));
        while(scanf("%c", &ch) && ch != '\n')
        {
            if(ch == ' ') continue;
            if(ch <= 'Z') a[ch - 'A']++;
            else a[ch - 'a']++;
            cnt1++;
        }
        while(scanf("%c", &ch) && ch != '\n')
        {
            if(ch == ' ' || !state) continue;
            if(ch <= 'Z')
            {
                if(a[ch - 'A']) a[ch - 'A']--;
                else state = false;
            }
            else
            {
                if(a[ch - 'a']) a[ch - 'a']--;
                else state = false;
            }
            cnt2++;
        }
        if(cnt1 != cnt2) state = false;
        if(state) printf("Case %d: Yes\n", ++cas);
        else printf("Case %d: No\n", ++cas);
    }

    return 0;
}
