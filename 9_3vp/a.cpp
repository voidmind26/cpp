#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e5 + 1;
int num[N];
int sum[N];
int hi[N];
int dis[N];

signed main() {
    int n, q, k;
    cin >> n >> q >> k;
    for (int i = 1;i <= n;i++) {
        cin >> num[i];
    }
    for (int i = 1;i <= n;i++) {
        sum[i] = sum[i - 1] + num[i];
        cin >> hi[i];
    }
    int pos = 0;
    for (int i = 1;i <= n;i++) {
        if (i - pos < k) {
            dis[i] = i - pos + dis[pos];
        }
        else {
            dis[i] = k;
        }
        if (hi[i] < hi[i + 1] && i != n) {
            pos = i;
        }
    }
    for (int i = 1;i <= q;i++) {
        int t;
        cin >> t;
        cout << sum[t] - sum[t - dis[t]] << endl;
    }
    return 0;
}