#include<bits/stdc++.h>
const int N = 5e6;
using namespace std;
const int M = 1e9 + 7;

#define int long long

void solve(int x, int& x2, int& x5) {
    while (x % 2 == 0) {
        x2++;
        x /= 2;
    }
    while (x % 5 == 0) {
        x5++;
        x /= 5;
    }
}

signed main() {
    int n;
    cin >> n;
    int ans2 = 0;
    int ans5 = 0;
    int cur2 = 0;
    int cur5 = 0;
    for (int i = 2;i <= n;i++) {
        int x = (4 * i - 2);
        int y = (i + 1);
        int y2, y5;
        int x2, x5;
        y2 = y5 = 0;
        x2 = x5 = 0;
        solve(x, x2, x5);
        solve(y, y2, y5);
        // cout << x << " " << x2 << " " << x5 << "\n";
        // cout << y << " " << y2 << " " << y5 << "\n";
        cur2 += x2 - y2;
        cur5 += x5 - y5;
        // cout << i << " " << cur2 << " " << cur5 << "\n";
        // cout << "\n";
        ans2 += cur2;
        ans5 += cur5;
    }
    cout << min(ans2, ans5) << endl;
    return 0;
}