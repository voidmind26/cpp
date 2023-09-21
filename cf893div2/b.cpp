#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
const int INF = 1e9 + 1;
int a[N];
int sdt[N];

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, d;
        cin >> n >> m >> d;
        for (int i = 1;i <= m; i++) {
            cin >> a[i];
        }
        int ans, anspos;
        ans = INF;
        a[0] = 1;
        a[m + 1] = n;
        int ori = 1;
        int tmp = 1;
        for (int i = 1; i <= m; i++) {
            if (a[i] == 1) {
                sdt[1] = 1;
                continue;
            }
            ori += max((a[i] - tmp - 1) / d, 0);
            ori++;
            tmp = a[i];
            sdt[i] = ori;
        }
        ori += max((n - tmp - 1) / d, 0);
        sdt[0] = 1;
        sdt[m + 1] = ori;
        int aft;
        if (a[1] != 1) {
            aft = max((a[2] - 1 - 1) / d, 0);
            if (ori - sdt[2] + 1 + 1 + aft < ans) {
                ans = ori - sdt[2] + 1 + 1 + aft;
                anspos = 1;
            }
            else if (ori - sdt[i + 1] + sdt[i - 1] + 1 + aft == ans) {
                anspos++;
            }
        }
        for (int i = 2;i < m; i++) {
            if (a[i] == 1) {
                ans = ori;
                anspos = 1;
                continue;
            }
            aft = max((a[i + 1] - a[i - 1] - 1) / d, 0);
            if (ori - sdt[i + 1] + sdt[i - 1] + 1 + aft < ans) {
                ans = ori - sdt[i + 1] + sdt[i - 1] + 1 + aft;
                anspos = 1;
            }
            else if (ori - sdt[i + 1] + sdt[i - 1] + 1 + aft == ans) {
                anspos++;
            }
        }
        aft = max((n - a[m - 1]) / d, 0);
        if (sdt[m - 1] + aft < ans) {
            ans = sdt[m - 1] + aft;
            anspos = 1;
        }
        else if (sdt[m - 1] + aft == ans) {
            anspos++;
        }
        cout << ans << " " << anspos << "\n";
    }
    return 0;
}