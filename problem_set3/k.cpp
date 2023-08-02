#include<iostream>
#include<algorithm>

using namespace std;
const int N = 101;
int dp[1001][1001];
int r[N];
int w[N];
int b[N];

int main() {
    int n, m, v;
    cin >> n >> m >> v;
    for (int i = 1;i <= n;i++) {
        cin >> w[i] >> b[i] >> r[i];
    }
    for (int i = 1;i <= n;i++) {
        for (int j = v;j >= r[i];j--) {
            for (int k = m;k >= b[i];k--)
                dp[j][k] = max(dp[j - r[i]][k - b[i]] + w[i], dp[j][k]);
        }
    }
    cout << dp[v][m] << endl;
    return 0;
}