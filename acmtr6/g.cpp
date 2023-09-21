#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n;
int d[110], a[N];
void add(int x) {
    for (int i = 60;i >= 0;i--) {
        if (x & (1ll << i)) {
            if (d[i])
                x ^= d[i];
            else {
                d[i] = x;
                break;
            }
        }
    }
}
signed main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(d, 0, sizeof d);
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            add(a[i]);
        }
        int ans = 0;
        for (int i = 60;i >= 0;i--)
            if ((ans ^ d[i]) > ans)
                ans = ans ^ d[i];
        cout << ans << endl;
    }
    return 0;
}