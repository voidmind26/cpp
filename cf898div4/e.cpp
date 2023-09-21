#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 2;
int a[N];

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        int l = 1;
        int r = 2e9;
        while (l < r) {
            int mid = (l + r) / 2;
            int check = 0;
            for (int i = 1;i <= n;i++) {
                check += max(mid - a[i], 0ll);
            }
            if (check > x) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        int check = 0;
        for (int i = 1;i <= n;i++) {
            check += max(l - a[i], 0ll);
        }
        if (check > x) {
            cout << l - 1 << endl;
        }
        else {
            cout << l << endl;
        }
    }
    return 0;
}