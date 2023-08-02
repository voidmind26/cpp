#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N = 55;
const int M = 1e5 + 1;
struct node {
    int a, b, c;

    bool operator < (const node& T)const {
        return c * T.b < T.c * b;
    }
}save[N];

int dp[M];
signed main() {
    int v, n;
    cin >> v >> n;
    for (int i = 1;i <= n;i++) {
        cin >> save[i].a;
    }
    for (int i = 1;i <= n;i++) {
        cin >> save[i].b;
    }
    for (int i = 1;i <= n;i++) {
        cin >> save[i].c;
    }
    sort(save + 1, save + 1 + n);
    for (int i = 1;i <= n;i++) {
        for (int j = v;j >= save[i].c;j--) {
            dp[j] = max(dp[j], dp[j - save[i].c] + save[i].a - j * save[i].b);
        }
    }
    int ans = 0;
    for (int i = 1;i <= v;i++) {
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
    return 0;
}