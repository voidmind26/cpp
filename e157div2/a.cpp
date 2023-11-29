#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, k;
        cin >> a >> b >> k;
        int ans;
        if ((a - b) * (a - c) > 0)
            ans = max(abs(a - c), abs(a - b));
        else
            ans = abs(a - c) + abs(a - b) + min(abs(a - c), abs(a - b));
        cout << ans << "\n";
    }
    return 0;
}