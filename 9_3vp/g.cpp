#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, p;
const int N = 1e5 + 1;
int hi[N];

bool check(int x) {
    int tmp = 0;
    for (int i = 1;i <= n;i++) {
        if (hi[i] > x) {
            tmp += (hi[i] - x) * 2;
        }
    }
    if (tmp >= p) {
        return true;
    }
    else {
        return false;
    }
}

int solve(int l, int r) {
    if (l >= r) {
        return l;
    }
    int mid = (l + r) / 2;
    if (check(mid)) {
        return solve(mid + 1, r);
    }
    else {
        return solve(l, mid);
    }
}

signed main() {
    cin >> n >> p;
    int mx = 0;
    for (int i = 1;i <= n;i++) {
        cin >> hi[i];
        mx = max(hi[i], mx);
    }
    int res = solve(1, mx) - 1;
    if (!check(res)) {
        cout << -1 << endl;
    }
    else {
        cout << res << endl;
    }
    return 0;
}