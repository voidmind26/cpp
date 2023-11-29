#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int gcd(int a, int b) {
    if (b) while ((a %= b) && (b %= a));
    return a + b;
}

int exgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a / b * x);
    return d;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    int x, y;
    exgcd(a, b, x, y);
    int g;
    g = gcd(a, b);
    x = (x % (b / g) + b / g) % (b / g);
    cout << x << "\n";
    return 0;
}