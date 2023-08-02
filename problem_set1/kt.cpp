#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <stack>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <utility>

using namespace std;
//#define Online_Judge
#define outstars cout << "***********************" << endl;
#define clr(a,b) memset(a,b,sizeof(a))
#define lson l , mid  , rt << 1
#define rson mid + 1 , r , rt << 1 | 1
//#define mid ((l + r) >> 1)
#define mk make_pair
#define FOR(i , x , n) for(int i = (x) ; i < (n) ; i++)
#define FORR(i , x , n) for(int i = (x) ; i <= (n) ; i++)
#define REP(i , x , n) for(int i = (x) ; i > (n) ; i--)
#define REPP(i ,x , n) for(int i = (x) ; i >= (n) ; i--)
const int MAXN = 50000 + 500;
const long long LLMAX = 0x7fffffffffffffffLL;
const long long LLMIN = 0x8000000000000000LL;
const int INF = 0x3f3f3f3f;
const int IMIN = 0x80000000;
const double e = 2.718281828;
#define eps 1e-8
#define DEBUG 1
#define mod 1000000007
typedef long long LL;
const double PI = acos(-1.0);
typedef double D;
typedef pair<int, int> pi;
///#pragma comment(linker, "/STACK:102400000,102400000")__int64 a[10050];
int n;
D x[MAXN], w[MAXN];
D work(D xx) {
    D ans = 0.0;
    FORR(i, 0, n) {
        D t = abs(xx - x[i]);
        ans += t * t * t * w[i];
    }
    return ans;
}
LL triSearch(D l, D r) {
    D mid, midmid, valueofmid, valueofmidmid;
    while (r - l > eps) {
        mid = (l + r) / 2;
        midmid = (mid + r) / 2;
        valueofmid = work(mid);
        valueofmidmid = work(midmid);
        if (valueofmid <= valueofmidmid)r = midmid;
        else l = mid;
    }
    cout << mid << endl;
    return LL(valueofmid + 0.5);
}
int main() {
    int  t;
    cin >> t;
    FORR(kase, 1, t) {
        scanf("%d", &n);
        FOR(i, 0, n) {
            scanf("%lf%lf", &x[i], &w[i]);
        }
        FOR(i, 0, n) {
            cout << x[i] << " " << w[i] << endl;
        }
        printf("Case #%d: ", kase);
        if (n == 1)printf("%lld\n", (LL)(work(x[0]) + 0.5));
        else printf("%lld\n", (LL)(triSearch(x[0], x[n - 1]) + 0.5));
    }
    return 0;
}