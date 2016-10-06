#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt  <<  1
#define rson m + 1, r, rt  <<  1 | 1
#define root 1, n, 1

const int maxn = 205;
const int maxm = 1e5 + 5;
const int mod = 10000;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;

typedef double db;
typedef long long LL;
typedef std :: pair< int, int > PII;
typedef std :: pair< LL, LL > PLL;
typedef std :: pair< db, db > PDD;

const db dInf = 1E90;
const LL lInf = ( LL ) 1E16;
const int Inf = 0x23333333;
const int N = 30005, Mo = 10007;

#define it iterator
#define rbg rbegin()
#define ren rend()
#define bg begin()
#define en end()
#define sz size()
#define fdi( i, x ) for ( typeof( x.rbg ) i=x.rbg; i!=x.ren; ++i )
#define foi( i, x ) for ( typeof( x.bg ) i=x.bg; i!=x.en; ++i )
#define fd( i, y, x ) for ( int i=( y )-1, lim=x; i>=lim; --i )
#define fo( i, x, y ) for ( int i=x, lim=y; i<lim; ++i )
#define mkp( A, B ) make_pair( A, B )
#define pub( x ) push_back( x )
#define pob( x ) pop_back( x )
#define puf( x ) push_front( x )
#define pof( x ) pop_front( x )
#define fi first
#define se second

inline int pwr( const int &x, const int &p )
{   
    if ( !p ) return 1;
    int temp = pwr( x, p >> 1 );
    temp = temp * temp % Mo;
    if ( p & 1 ) temp = temp * x % Mo;
    return temp;
}

int gcd( const int A, const int B )
{
    return ( B ? gcd( B, A % B ) : A );
}

namespace LCT
{
    struct node
    {
        int fa, s[2];
        int _k, _b, k, b;
    } a[N];
    int grpfa[N];

    inline void update( const int &x )
    {
        a[x]._k = a[x].k, a[x]._b = a[x].b;
        const int &l = a[x].s[0], &r = a[x].s[1];
        if ( l ) 
        {
            a[x]._k = ( a[x]._k * a[l]._k ) % Mo;
            a[x]._b = ( a[l]._k * a[x]._b + a[l]._b ) % Mo;
        }
        if ( r ) 
        {
            a[x]._b = ( a[x]._k * a[r]._b + a[x]._b ) % Mo;
            a[x]._k = ( a[x]._k * a[r]._k ) % Mo;
        }
    }

    inline bool top( const int &x )
    {
        const int &y = a[x].fa;
        return ( !y ) || a[y].s[0]!=x && a[y].s[1]!=x;
    }

    inline int dir( const int &x )
    {
        const int &y = a[x].fa;
        return a[y].s[1] == x;
    }

    inline void rotate( const int &x )
    {   
        int y = a[x].fa, z = a[y].fa;
        bool p = dir( x ), q = p ^ 1;
        int A = a[x].s[q];
        if ( !top( y ) ) a[z].s[ dir( y ) ] = x;
        a[y].s[p] = A, a[y].fa = x;
        a[x].s[q] = y, a[x].fa = z;
        if ( A ) a[A].fa = y;
        update( y );
    }

    inline void splay( const int &x )
    {   
        while ( !top( x ) )
        {
            int y = a[x].fa, z = a[y].fa;
            if ( top( y ) ) rotate( x );
            else if ( top( z ) || dir( y )^dir( x ) ) 
                rotate( x ), rotate( x );
            else rotate( y ), rotate( x );
        }
        update( x );
    }

    inline void access( const int &x )
    {   
        for ( int _x=x, y=0; _x; _x=a[_x].fa )
            splay( _x ), a[_x].s[0] = y, y = _x;
        splay( x );
    }

    inline int getself( const int &x )
    {
        access( x );
        int k = ( 1 - a[x]._k + Mo ) % Mo, b = a[x]._b;
        if ( gcd( k, Mo )!=1 ) return ( b ? -1 : -2 );
        else return b * pwr( k, Mo - 2 ) % Mo;
    }

    inline int gettail( const int &x )
    {
        int _x = x; access( x );
        for ( ; a[_x].s[1]; _x=a[_x].s[1] );
        splay( _x );
        return _x;
    }

    inline int query( const int &x )
    {
        int core = getself( grpfa[ gettail( x ) ] );
        if ( core < 0 ) return core;
        access( x );
        return ( a[x]._k * core + a[x]._b ) % Mo;
    }

    inline bool isancestor( const int &x, const int &y )
    {
        if ( x==y ) return 1;
        access( y ), splay( x );
        return a[x].s[0] == y;
    }

    inline void change( const int &x, const int &_y, const int &k, const int &b )
    {
        int tail = gettail( x );
        bool inloop = isancestor( x, grpfa[tail] );
        access( x ), a[x].s[1] = a[ a[x].s[1] ].fa = 0;
        if ( inloop ) 
        {
            access( tail );
            a[tail].fa = grpfa[tail], grpfa[tail] = 0;
        }
        a[x].fa = 0;
        if ( isancestor( x, _y ) ) grpfa[x] = _y;
        else a[x].fa = _y; 
        a[x].k = k, a[x].b = b, access( x );
    }
}

int n;

void preprocessing()
{
    int fa; scanf( "%d", &n ), ++n;
    fo ( i, 1, n ) 
    {
        scanf( "%d%d%d", &LCT :: a[i].k, &fa, &LCT :: a[i].b );
        if ( LCT :: isancestor( i, fa ) ) LCT :: grpfa[i] = fa;
        else LCT :: a[i].fa = fa;
    }
}

void solve()
{
    char type;
    int T, x, y, k, b; 
    scanf( "%d", &T );
    fo ( Case, 0, T )
    {
        for ( type='`'; type!='A' && type!='C'; type=getchar() );
        if ( type=='A' ) 
        {
            scanf( "%d", &x );
            printf( "%d\n", LCT :: query( x ) );
        }
        else 
        {
            scanf( "%d%d%d%d", &x, &k, &y, &b );
            LCT :: change( x, y, k, b );
        }
    }
}

int main()
{
    preprocessing();
    solve();
    return 0;
}
