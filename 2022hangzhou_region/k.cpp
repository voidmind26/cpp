#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[3010][3010][2], mx[3010];
vector<ll> e[3010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        int m;cin >> m;
        for (int j = 1;j <= m;j++) {
            int x;cin >> x;
            e[i].push_back(x);
        }
        mx[i] = e[i].back();
    }
    for (int i = 0;i <= k;i++) {
        dp[0][i][1] = -1e18;
    }
    for (int i = 1;i <= n;i++) {
        int len = e[i].size();
        for (int j = 0;j <= k;j++) {
            dp[i][j][0] = dp[i - 1][j][0];
            dp[i][j][1] = dp[i - 1][j][1];
        }
        for (int j = len;j <= k;j++) {
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - len][0] + mx[i]);
            dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - len][1] + mx[i]);
        }
        for (int j = 0;j < len - 1;j++) {
            for (int z = (j + 1);z <= k;z++) {
                dp[i][z][1] = max(dp[i][z][1], dp[i - 1][z - (j + 1)][0] + e[i][j]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0;i <= k;i++) {
        ans = max(ans, dp[n][i][0]);
        ans = max(ans, dp[n][i][1]);
    }
    cout << ans << "\n";
}

