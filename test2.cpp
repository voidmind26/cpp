#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;
int last[N];
int a[N];
int mi[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            mi[i] = 0x7fffffff;
            last[i] = -1;
            cin >> a[i];
        }
        for (int i = 1;i <= n;i++) {
            if (last[a[i]] == -1) {
                last[a[i]] = i;
            }
            else {
                mi[a[i]] = min(mi[a[i]], i - last[a[i]] + 1);
                last[a[i]] = i;
            }
        }
        int ans = 0x7fffffff;
        for (int i = 1;i <= n;i++) {
            ans = min(ans, mi[i]);
        }
        if (ans == 0x7fffffff) {
            ans = -1;
        }
        cout << ans << "\n";
    }

    return 0;
}