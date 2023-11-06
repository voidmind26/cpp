#include<bits/stdc++.h>

using namespace std;

const int N = 35;
int a[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        bool ok = 1;
        int ans = 0;
        for (int i = n - 1;i >= 1;i--) {
            if (a[i + 1] == 0) {
                ok = 0;
                break;
            }
            while (a[i] >= a[i + 1]) {
                a[i] /= 2;
                ans++;
            }
        }
        if (ok) {
            cout << ans << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
    return 0;
}