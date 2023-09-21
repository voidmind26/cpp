#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5 + 1;
int a[N];
int h[N];
int sum[N];
int belong[N];
int n, k;

int solve(int l, int r) {
    if (r <= l) {
        return l;
    }
    int mid = (l + r) / 2;
    bool flag = 0;
    for (int i = n;i - mid >= 0;i--) {
        if (sum[i] - sum[i - mid] <= k && belong[i] == belong[i - mid + 1]) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        return solve(mid+1, r);
    }
    else {
        return solve(l, mid);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1;i <= n;i++) {
            sum[i] = 0;
            belong[i] = 0;
            cin >> a[i];
        }
        for (int i = 1;i <= n;i++) {
            cin >> h[i];
        }
        int flag = 1;
        belong[1] = 1;
        for (int i = 2;i <= n;i++) {
            if (h[i - 1] % h[i] == 0) {
                belong[i] = flag;
            }
            else {
                flag++;
                belong[i] = flag;
            }
        }
        for (int i = 1;i <= n;i++) {
            sum[i] += sum[i - 1] + a[i];
        }

        // for (int i = 1;i <= n;i++) {
        //     cout << belong[i] << " ";
        // }
        // cout << endl;
        // for (int i = 1;i <= n;i++) {
        //     cout << sum[i] << " ";
        // }
        // cout << endl;

        int res = solve(1, n);
        flag = 0;
        for (int i = n;i - res >= 0;i--) {
            if (sum[i] - sum[i - res] <= k && belong[i] == belong[i - res + 1]) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << res << endl;
        }
        else {
            cout << res - 1 << endl;
        }
    }
    return 0;
}