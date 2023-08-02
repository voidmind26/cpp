#include<iostream>
#include<cmath>
#define int long long

using namespace std;

int ex_gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

signed main() {
    int x, y, m, n, l;
    cin >> x >> y >> m >> n >> l;
    int ta = n - m;
    int tb = l;
    int c = x - y;
    if (ta < 0) {
        ta = -ta;
        c = -c;
    }
    int d = ex_gcd(ta, tb, x, y);
    if (c % d != 0) {
        cout << "Impossible\n";
    }
    else {
        cout << ((x * (c / d)) % (l / d) + (l / d)) % (l / d) << endl;
    }
    return 0;
}