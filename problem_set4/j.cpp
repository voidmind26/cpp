#include<iostream>

#define int long long 
using namespace std;
const int N = 2003;
const int Mod = 1e4 + 7;
int c[N][N];

int qpow(int x, int k) {
    if (k == 0) {
        return 1;
    }
    if (k % 2 == 0) {
        return (qpow(x, k / 2) * qpow(x, k / 2)) % Mod;
    }
    else {
        return (x%Mod * qpow(x, k / 2) * qpow(x, k / 2)) % Mod;
    }
}

signed main() {
    int n, m, k, a, b;
    cin >> a >> b >> k >> n >> m;
    c[0][0] = 1;
    c[1][0] = 1;
    c[1][1] = 1;
    a %= Mod;
    b %= Mod;
    for (int i = 2;i <= k;i++) {
        for (int j = 0;j <= i;j++) {
            if (j == 0) {
                c[i][j] = 1;
            }
            else {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % Mod;
            }
        }
    }
    cout << (c[k][m] * qpow(b, m) * qpow(a, n)) % Mod << endl;
    return 0;
}   