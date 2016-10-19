#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt  <<  1
#define rson m + 1, r, rt  <<  1 | 1
#define root 1, n, 1

const int maxn = 105;
const int maxm = 1e5 + 5;
const int mod = 10000;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;

std::map<std::string, int> P, D, S, Name;
std::map<std::string, int>::iterator it;

struct node
{
    int x, y, z;
    std::string name;
    node(int _x = 0, int _y = 0, int _z = 0, string _name = ""): x(_x), y(_x), z(_z), name(_name) {}
    bool operator < (const node &b) const
    {
        if(x == b.x && y == b.y && z == b.z) return name < b.name;
        else if(x == b.x && y == b.y) return z > b.z;
        else if(x == b.x) return y > b.y;
        else return x > b.x;
    }
} a[25];

void init()
{
    P.clear();
    D.clear();
    S.clear();
    Name.clear();
}

bool judge(string s, string p, int x, int y)
{
    if(x > y)
    {
        P[s] += 3; D[s] += x - y; S[s] += x;
        P[p] += 0; D[p] += y - x; S[p] += y;
    }

    int tot(0);
    for(it = P.begin(); it != P.end(); it++)
    {
        std::string tmp = it -> first;
        // if(tmp == "BERLAND")
        //     a[0] = node(it -> second, D[tmp], S[tmp], tmp);
        // else 
        //     a[++tot] = node(P[tmp], D[tmp], S[tmp], tmp);
        if(tmp == "BERLAND")
        {
            a[0].x = it -> second;
            a[0].y = D[tmp];
            a[0].z = S[tmp];
            a[0].name = tmp;
        }
        else
        {
            a[++tot].x = P[tmp];
            a[tot].y = D[tmp];
            a[tot].z = S[tmp];
            a[tot].name = tmp;
        }
    }
    sort(a, a + tot + 1);
    bool state = false;
    if(a[0].name == "BERLAND" || a[1].name == "BERLAND")
        state = true;

    if(x > y)
    {
        P[s] -= 3; D[s] -= x - y; S[s] -= x;
        P[p] -= 0; D[p] -= y - x; S[p] -= y;
    }

    return state;
}

int main()
{
    init();
    int x, y;
    for(int i = 0; i < 5; i++)
    {
        std::string s, p;
        cin >> s >> p;
        scanf("%d:%d", &x, &y);
        Name[s]++; Name[p]++;
        if(x == y)
        {
            P[s] += 1; D[s] += x - y; S[s] += x;
            P[p] += 1; D[p] += y - x; S[p] += y;
        }
        else if(x > y)
        {
            P[s] += 3; D[s] += x - y; S[s] += x;
            P[p] += 0; D[p] += y - x; S[p] += y;
        }
        else if(x < y)
        {
            P[s] += 0; D[s] += x - y; S[s] += x;
            P[p] += 3; D[p] += y - x; S[p] += y;
        }
    }

    std::string op;
    for(it = P.begin(); it != P.end(); it++)
        if(Name[it -> first] == 2 && it -> first != "BERLAND")
            op = it -> first;
    bool state = false;
    int Min = inf;
    for(int i = 0; i <= 100; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(judge("BERLAND", op, i, j))
            {
                state = true;
                if(i - j < Min) { Min = i - j; x = i; y = j; }
                else if(i - j == Min)
                {
                    if(j < y) { x = i; y = j; }
                }
            }
        }
    }

    if(state) printf("%d:%d\n", x, y);
    else printf("IMPOSSIBLE\n");

    return 0;
}
