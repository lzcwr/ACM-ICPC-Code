#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 105;

int main()
{
    int n, a[maxn];

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);

    int i, tot(10), penalty(0);

    for(i = 0; i < n; i++)
    {
        if(tot + a[i] <= 360)
            tot += a[i];
        else if(tot + a[i] > 360 && tot + a[i] <= 720)
        {
            tot += a[i];
            penalty += tot - 360;
        }
        else if(tot + a[i] > 720) break;
    }

    printf("%d %d\n", i, penalty);

    return 0;
}
