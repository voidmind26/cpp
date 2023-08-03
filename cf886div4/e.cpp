#include<iostream>
#define int unsigned long long
using namespace std;
const int N = 2e5 + 1;
int s[N];
int n, c;
int sum;
int ssum;

bool check(int x) {
    if (4ull * n * x * x + 4ull * sum * x + ssum >= c) {
        return 1;
    }
    else {
        return 0;
    }
}

int solve(int l, int r) {
    if (l >= r) {
        return l;
    }
    int mid = (l + r) / 2;
    if (check(mid)) {
        return solve(l, mid);
    }
    else {
        return solve(mid + 1ll, r);
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        sum = 0;
        cin >> n >> c;
        for (int i = 1;i <= n;i++) {
            cin >> s[i];
            sum += s[i];
            ssum += s[i] * s[i];
        }
        cout << solve(1, 2e9) << endl;
    }
    return 0;
}