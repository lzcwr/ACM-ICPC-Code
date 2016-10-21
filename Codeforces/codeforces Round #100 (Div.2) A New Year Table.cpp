#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);

int main()
{
    double n, R, r;
    while(cin >> n >> R >>r)
    {
        if(n == 1 || n == 2)
        {
            if(R >= r * n)
                printf("YES\n");
            else
                printf("NO\n");
            continue;
        }
        double d=((n-2.0)*180.0/n)/2.0;
        if(R >= r + r / cos(d * (pi / 180.0)))
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return 0;
}
