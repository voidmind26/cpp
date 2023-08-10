#include<iostream>
#include<cstdio>

using namespace std;
#define int long long 
const int N = 5e3 + 1;
int mod = 1e9 + 7;
int dp[N][N];// level i   rk=j
int pw[N];
int p, n;

int qpow(int x, int y) {
    int ans = 1;
    x %= mod;
    while (y) {
        if (y & 1)ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

int inv(int x) {
    return qpow(x, mod - 2);
}

signed main() {
    // freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> p;
        dp[0][0] = 1;
        pw[0] = 1;
        for (int i = 1;i <= n;i++) {
            dp[i][0] = 1;
            dp[0][i] = 0;
            pw[i] = pw[i - 1] * p;
            pw[i] %= mod;
        }
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                dp[i][j] = pw[j] * dp[i - 1][j] + (((pw[n] - pw[j - 1]) % mod + mod) % mod) * dp[i - 1][j - 1];
                dp[i][j] %= mod;
            }
        }
        int sum = 0;
        for (int i = 0;i <= n;i++) {
            sum += i * dp[n][i];
            sum %= mod;
        }
        cout << (sum * inv(qpow(p, n * n))) % mod << endl;
    }
    return 0;
}