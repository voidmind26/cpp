#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int N = 5, Mod = 1e9 + 7;
int k, T;
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
void read(int& x) {
    char ch, last;
    while (ch = getchar(), ch > '9' || ch < '0')last = ch;
    for (x = 0;ch >= '0' && ch <= '9';ch = getchar())
        x = x * 10 + ch - '0';
    if (last == '-')x = -x;
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
    int n;
    read(T);
    matrix st;
    for (int i = 1;i <= 3;i++)
        st.mx[1][i] = 1;
    st.n = 1;
    st.m = 3;
    matrix c;
    c.n = c.m = 3;
    c.mx[1][1] = 1;
    c.mx[1][2] = 1;
    c.mx[1][3] = 0;
    c.mx[2][1] = 0;
    c.mx[2][2] = 0;
    c.mx[2][3] = 1;
    c.mx[3][1] = 1;
    c.mx[3][2] = 0;
    c.mx[3][3] = 0;
    while (T--) {
        read(n);
        k = n - 1;
        if (n <= 3) {
            printf("1\n");
            continue;
        }
        matrix tmp, ans;
        ans.n = 4;
        ans.m = 4;
        ans.build();
        tmp = c;
        ans = st * pow(tmp, k);
        printf("%lld\n", ans.mx[1][1]);
    }
    return 0;
}