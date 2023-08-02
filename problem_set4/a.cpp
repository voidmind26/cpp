#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int N = 70;
int Mod;
struct matrix {
    ll mx[N][N];
    int n, m;
    matrix() {
        memset(mx, 0, sizeof(mx));
    }
    inline void build() {
        for (int i = 1;i <= n;i++)mx[i][i] = 1;
    }
};
matrix operator *(const matrix& x, const matrix& y) {
    matrix res;
    int n = x.n;
    int m = y.m;
    res.n = n;
    res.m = m;
    for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                res.mx[i][j] = (res.mx[i][j] + x.mx[i][k] * y.mx[k][j] % Mod) % Mod;
    return res;
}

matrix pow(matrix aim, int k) {
    matrix res;
    res.n = aim.n;
    res.m = aim.m;
    res.build();
    while (k != 0) {
        if ((k & 1) == 1)
            res = res * aim;
        aim = aim * aim;
        k >>= 1;
    }
    return res;
}
int main() {
    int n, m, k;
    matrix ans, a;
    cin >> n >> k >> m;
    a.n = n;
    a.m = n;
    Mod = m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> a.mx[i][j];
        }
    }

    ans.n = 2 * n;
    ans.m = 2 * n;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            ans.mx[i][j] = a.mx[i][j];
            ans.mx[i + n][j] = a.mx[i][j];
        }
        ans.mx[i + n][i + n] = 1;
    }
    ans = pow(ans, k);
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cout << ans.mx[i + n][j] << " ";
        }
        cout << endl;
    }
    return 0;
}