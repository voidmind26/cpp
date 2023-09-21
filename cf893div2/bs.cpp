#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 1;
int a[N];
int s[N];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, d;
        cin >> n >> m >> d;
        for (int i = 1;i <= m;i++) {
            cin >> a[i];
        }
        int ori = 1;
        int tmp = 1;
        for (int i = 1;i <= m;i++) {
            if (a[i] == 1) {
                s[i] = 1;
                continue;
            }
            ori += (a[i] - tmp - 1) / d;
            ori++;
            s[i] = ori;
            tmp = a[i];
        }
        ori += (n - a[m]) / d;
        int ans = 1e9 + 7;
        int num = 0;
        for (int i = 1;i <= m;i++) {
            if (a[i] == 1) {
                ans = ori;
                num = 1;
                continue;
            }
            int aft;
            if (i == 1) {
                aft = (a[i + 1] - 1 - 1) / d;
                if (ori - s[i + 1] + 1 + 1 + aft < ans) {
                    ans = ori - s[i + 1] + 1 + 1 + aft;
                    num = 1;
                }
                continue;
            }
            if (i == m) {
                aft = (n - a[i - 1]) / d;
                if (s[i - 1] + aft < ans) {
                    ans = s[i - 1] + aft;
                    num = 1;
                }
                else if (s[i - 1] + aft == ans) {
                    num++;
                }
                continue;
            }
            aft = (a[i + 1] - a[i - 1] - 1) / d;
            if (ori - s[i + 1] - s[i - 1] + 1 + aft < ans) {
                ans = ori - s[i + 1] - s[i - 1] + 1 + aft;
                num = 1;
            }
            else if (ori - s[i + 1] - s[i - 1] + 1 + aft == ans) {
                num++;
            }
        }
        cout << ans << " " << num << endl;
    }


    return 0;
}