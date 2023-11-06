#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
int a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int l = 0;
        string s;
        cin >> s;
        int n = s.length();
        int r = n + 1;
        for (int i = 1;i <= n;i++) {
            if (s[i - 1] == '0') {
                a[i] = 0;
            }
            else if (s[i - 1] == '1') {
                a[i] = 1;
            }
            else {
                a[i] = -1;
            }
        }
        a[0] = 1;
        a[n + 1] = 0;
        for (int i = n + 1;i >= 0;i--) {
            if (a[i] == 0) {
                r = min(r, i);
            }
            if (a[i] == 1) {
                l = max(i, l);
            }
        }
        int ans = r - l + 1;
        if (r == n + 1) {
            ans--;
        }
        if (l == 0) {
            ans--;
        }
        cout << ans << "\n";
    }

    return 0;
}