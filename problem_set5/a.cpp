#include<iostream>

#define int long long
using namespace std;

const int N = 55;
int p[N];
int a[N];

void build(int x) {
    for (int i = N;i >= 0;i--) {
        if (x & (1ll << i)) {
            if (p[i]) {
            }
            else {
                p[i] = x;
                break;
            }
        }
    }
}

signed main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        build(a[i]);
    }
    int ans = 0;
    for (int i = N; i >= 0; i--) {
        ans = max(ans, ans ^ p[i]);
    }
    cout << ans << endl;
    return 0;
}