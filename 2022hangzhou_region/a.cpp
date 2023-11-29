#include<iostream>
#define int long long
using namespace std;


int n, m, X, Y, sum;


int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}


void exgcd(int a, int b) {
    if (b == 0) {
        X = 1;
        Y = 0;
        return;
    }
    exgcd(b, a % b);
    int t = X;
    X = Y;
    Y = t - a / b * Y;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
    }
    int x, y;
    int tmp1 = n, tmp2 = (n + 1) * n / 2;
    int gcd1 = gcd(tmp1, tmp2), gcd2 = gcd(gcd1, m), k = gcd1 / gcd2;

    int l = 0, r = 2000000000;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (sum + mid * gcd2 >= m) {
            y = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    exgcd(k, m);
    x = X * y / gcd(k, m);
    if (n % 2 == 0)//n/2
    {
        int s = (n + 2) / 2 * x, d = -1 * x;
        s = ((s % m) + m) % m;
        d = ((d % m) + m) % m;
        cout << ((n * s % m + ((((n + 1) * n / 2) % m) * d) % m) + sum) % m << "\n";
        cout << s << " " << d << "\n";
    }
    else {
        int s = -n * x, d = 2 * x;
        s = ((s % m) + m) % m;
        d = ((d % m) + m) % m;
        cout << ((n * s % m + ((((n + 1) * n / 2) % m) * d) % m) + sum) % m << "\n";
        cout << s << " " << d << "\n";
    }
    return 0;
}
// 
// kx+m*?=y
// ax+by =c