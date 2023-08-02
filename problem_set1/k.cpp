#include<iostream>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
const int N = 5e4 + 1;
#define eps 1e-8

double dis[N];
double w[N];
int n;


double f(double x) {
    double res = 0.0;
    for (int i = 1;i <= n;i++) {
        double xx = abs(x-dis[i]);
        res += xx * xx * xx * w[i];
    }
    return res;
}

int solve(double l, double r) {
    if (r - l <= eps) {
        return (int)(round(f((r - l) / 3.0 + l)));
    }
    double mid1 = (r - l) / 3.0 + l;
    double mid2 = r - (r - l) / 3.0;
    if (f(mid1) >= f(mid2)) {
        return solve(mid1, r);
    }
    else {
        return solve(l, mid2);
    }
}

signed main() {
    int t;
    cin >> t;
    for (int o = 1;o <= t;o++) {
        double mi, mx;
        mx = -1;
        mi = 1e6 + 1;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> dis[i];
            cin >> w[i];
            mx = max(dis[i], mx);
            mi = min(dis[i], mi);
        }
        if (n != 1)
            cout << "Case #" << o << ": " << solve(mi, mx) << endl;
        else
            cout << "Case #" << o << ": " << (int)(round(f(dis[1]))) << endl;
    }

    return 0;
}