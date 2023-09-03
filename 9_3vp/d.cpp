#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, m;
    int sum = 0;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        int a;
        cin >> a;
        sum += a;
    }
    if (sum >= m) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
    return 0;
}