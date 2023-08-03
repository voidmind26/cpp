#include<iostream>
using namespace std;
#define int long long
const int N = 1e5 + 2;
const int mod = 1e9 + 7;
int k[N], b[N], to[N];
int bz[N][30][2];
int bzto[N][30];
int p2[30];
int n, q;

signed main() {
    p2[0] = 1;
    for (int i = 1;i < 30;i++) {
        p2[i] = p2[i - 1] * 2;
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 1;i <= n;i++) {
            cin >> k[i];
        }
        for (int i = 1;i <= n;i++) {
            cin >> b[i];
        }
        for (int i = 1;i <= n;i++) {
            cin >> to[i];
        }
        for (int i = 0;i < 30;i++) {
            for (int j = 1;j <= n;j++) {
                if (i == 0) {
                    bzto[j][i] = to[j];
                    bz[j][i][0] = k[to[j]];
                    bz[j][i][1] = b[to[j]];
                }
                else {
                    bzto[j][i] = bzto[bzto[j][i - 1]][i - 1];
                    bz[j][i][1] = bz[j][i - 1][1] * bz[bzto[j][i - 1]][i - 1][0] % mod + bz[bzto[j][i - 1]][i - 1][1];
                    bz[j][i][1] %= mod;
                    bz[j][i][0] = bz[j][i - 1][0] * bz[bzto[j][i - 1]][i - 1][0] % mod;
                }
            }
        }
        for (int i = 1;i <= q;i++) {
            int x, l, y;
            cin >> x >> l >> y;
            int ansk = 1;
            int ansb = 0;
            for (int i = 29;i >= 0;i--) {
                if (p2[i] <= l) {
                    l -= p2[i];
                    ansk *= bz[x][i][0];
                    ansk %= mod;
                    ansb = ansb * bz[x][i][0] + bz[x][i][1];
                    ansb %= mod;
                    x = bzto[x][i];
                }
                if (l == 0) {
                    break;
                }
            }
            int ans = y * ansk % mod + ansb;
            ans %= mod;
            cout << ans << endl;
        }
    }
    return 0;
}