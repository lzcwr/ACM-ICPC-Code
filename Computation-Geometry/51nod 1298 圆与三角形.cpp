#include <bits/stdc++.h>
#ifdef __WINDOWS_
    #include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt  <<  1
#define rson m + 1, r, rt  <<  1 | 1
#define root 1, n, 1

const int maxn = 55;
const int maxm = 1e5 + 5;
const int mod = 10000;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
double torad(double deg) { return deg/180 * PI; }

struct Point
{
  double x, y;
  Point(double x=0, double y=0):x(x),y(y) { }
};

Point operator + (const Point& A, const Point& B) { return Point(A.x+B.x, A.y+B.y); }
Point operator - (const Point& A, const Point& B) { return Point(A.x-B.x, A.y-B.y); }
Point operator * (const Point& A, double p) { return Point(A.x*p, A.y*p); }
Point operator / (const Point& A, double p) { return Point(A.x/p, A.y/p); }

bool operator < (const Point& a, const Point& b)
{
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int dcmp(double x) { if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1; }

bool operator == (const Point& a, const Point &b)
{
  return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}

double dist(const Point& A, const Point& B) {return sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2));}
double Dot(const Point& A, const Point& B) { return A.x*B.x + A.y*B.y; }
double Length(const Point& A) { return sqrt(Dot(A, A)); }
double Angle(const Point& A, const Point& B) { return acos(Dot(A, B) / Length(A) / Length(B)); }
double Cross(const Point& A, const Point& B) { return A.x*B.y - A.y*B.x; }
double Area2(Point A, Point B, Point C) {return Cross(B-A, C-A);}

Point Rotate(const Point& A, double rad)
{
  return Point(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}
Point GetLineIntersection(const Point& P, const Point& v, const Point& Q, const Point& w)
{
  Point u = P-Q;
  double t = Cross(w, u) / Cross(v, w);
  return P+v*t;
}

double DistanceToLine(const Point& P, const Point& A, const Point& B)
{
  Point v1=B-A, v2=P-A;
  return fabs(Cross(v1,v2)) / Length(v1);
}

double DistanceToSegment(const Point& P, const Point& A, const Point& B)
{
  if(A == B) return Length(P-A);
  Point v1 = B - A, v2 = P - A, v3 = P - B;
  if(dcmp(Dot(v1, v2)) < 0) return Length(v2);
  else if(dcmp(Dot(v1, v3)) > 0) return Length(v3);
  else return fabs(Cross(v1, v2)) / Length(v1);
}

Point GetLineProjection(const Point &P, const Point &A,const Point &B)
{
    Point v = B - A;
    return A+v*(Dot(v, P-A) / Dot(v, v));
}

bool SegmentProperIntersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2)
{
  double c1 = Cross(a2-a1,b1-a1), c2 = Cross(a2-a1,b2-a1),
  c3 = Cross(b2-b1,a1-b1), c4=Cross(b2-b1,a2-b1);
  return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}

bool OnSegment(const Point& p, const Point& a1, const Point& a2)
{
  return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0;
}

int main()
{
    int t;
    Point s, p[5];
    double r, x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf", &s.x, &s.y, &r);
        for(int i = 0; i < 3; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        int ans = 0;
        x = DistanceToSegment(s, p[0], p[1]);
        if(x <= r) ans++;
        x = DistanceToSegment(s, p[0], p[2]);
        if(x <= r) ans++;
        x = DistanceToSegment(s, p[1], p[2]);
        if(x <= r) ans++;
        bool state = false;
        for(int i = 0; i < 3; i++)
        {
            if(dist(s, p[i]) > r)
            {
                state = true;
                break;
            }
        }
        if(ans >= 1 && state) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
