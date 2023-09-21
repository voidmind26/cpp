#include<bits/stdc++.h>

using namespace std;
const int N = 1e3 + 1;
int a[N];

int main() {
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> a[n - i + 1];
        }
        int ans = 0;
        for (int i = 2;i < n;i++) {
            if (a[i + 1] - a[i] != a[i] - a[i - 1]) {
                ans = n - i + 1;
                break;
            }
        }
        if (ans == 0) {
            ans = 1;
        }
        cout << ans << endl;
    }
    return 0;
}