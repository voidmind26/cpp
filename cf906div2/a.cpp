#include<bits/stdc++.h>

using namespace std;

map<int, int>mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        mp.clear();
        int n;
        cin >> n;
        int mx = -1;
        int mn = 1e9 + 1;
        for (int i = 1;i <= n;i++) {
            int t;
            cin >> t;
            mp[t]++;
            mx = max(mx, t);
            mn = min(mn, t);
        }
        if (mp.size() > 2) {
            cout << "No\n";
        }
        else {
            if (abs(mp[mx] - mp[mn]) > 1) {
                cout << "No\n";
            }
            else {
                cout << "Yes\n";
            }
        }
    }
    return 0;
}