#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#define Vector Point
#define Segment Line
using namespace std;
typedef long long ll;

const double pi = acos(-1.0);
const double eps = 1e-8;

inline int sgn(double x) {
    if (fabs(x) < eps)return 0;
    else return x < 0 ? -1 : 1;
}
inline int dcmp(double x, double y) {
    if (fabs(x - y) < eps)return 0;
    else return x < 0 ? -1 : 1;
}

struct Point {
    ll x, y;
    Point() {}
    Point(ll x, ll y) :x(x), y(y) {}
    Point operator + (Point B) { return Point(x + B.x, y + B.y); }
    Point operator - (Point B) { return Point(x - B.x, y - B.y); }
};

struct Line {
    Point p1, p2;
    Line() {
    }

    Line(Point p1, Point p2) :p1(p1), p2(p2) {}
};

inline ll Dot(Vector A, Vector B) {
    return A.x * B.x + A.y * B.y;
}

inline ll Cross(Vector A, Vector B) {
    return A.x * B.y - A.y * B.x;
}

inline double Distance(Point A, Point B) {
    //return hypot((double)A.x - B.x, (double)A.y - B.y);
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

inline double Dis_point_line(Point p, Line v) {
    return abs((double)Cross(p - v.p1, v.p2 - v.p1)) / Distance(v.p1, v.p2);
}

inline double Dis_point_seg(Point p, Segment v) {
    if ((Dot(p - v.p1, v.p2 - v.p1)) < 0 || (Dot(p - v.p2, v.p1 - v.p2)) < 0) {
        return min(Distance(p, v.p1), Distance(p, v.p2));
    }
    return Dis_point_line(p, v);
}
const int N = 1e4 + 1;
Point shelter[N];
Point roate[N];
double ans[N];

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 1;i <= m;i++) {
        scanf("%lld%lld", &roate[i].x, &roate[i].y);
    }
    for (int i = 1;i <= n;i++) {
        scanf("%lld%lld", &shelter[i].x, &shelter[i].y);
        ans[i] = 1e18;
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j < m;j++) {
            Segment tmp = Segment(roate[j], roate[j + 1]);
            ans[i] = min(Dis_point_seg(shelter[i], tmp), ans[i]);
        }
        printf("%.4lf\n", ans[i]);
    }
    return 0;
}