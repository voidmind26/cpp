#include<iostream>

using namespace std;
#define int long long
const int N = 1e4 + 1;
const int M = 1e7 + 1;
int w[N];
int r[N];
int dp[M];

signed main() {
    int n, v;
    cin >> v >> n;
    for (int i = 1;i <= n;i++) {
        cin >> r[i] >> w[i];
    }
    for (int i = 1;i <= n;i++) {
        for (int j = r[i];j <= v;j++) {
            dp[j] = max(dp[j], dp[j - r[i]] + w[i]);
        }
    }
    cout << dp[v] << endl;
    return 0;
}