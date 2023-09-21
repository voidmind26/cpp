#include<iostream>
#define ll long long
using namespace std;
const int M = 998244353;
int a[1001];
int n, k;
ll jc[1005];
void mem(ll n) {
    jc[1] = 1;
    jc[0] = 1;
    for (int i = 2;i <= n;i++) {
        jc[i] = (jc[i - 1] * i) % M;
    }
}
ll qpow(ll x, ll p) {
    ll res = 1;
    x %= M;
    for (;p;p >>= 1, x = (x * x) % M) {
        if (p & 1) {
            res *= x;
            res %= M;
        }
    }
    return res % M;
}
ll inv(ll x) {
    return qpow(x, M - 2);
}
ll qc(ll n, ll m) {
    return ((jc[n] * inv(jc[m])) % M * inv(jc[n - m])) % M;
}
int dfs(int deep, int r) {
    if (deep == n) {
        if (r <= a[n]) {
            return qc(r, a[deep]);
        }
        else {
            return 0;
        }
    }
    for (int i = 1;i <= a[deep];i++) {
        return (qc(i, a[i]) % M * dfs(deep + 1, r - i) % M) % M;
    }
}
int main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1;i <= a[1];i++)
        ans += qc(i, a[1]) * dfs(2, k - i);
    cout << ans << endl;
    return 0;
}