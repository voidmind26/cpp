#include<bits/stdc++.h>

using namespace std;

int to[27];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1;i <= 26;i++) {
            to[i] = 99;
        }
        string s;
        cin >> s;
        int mxc = 0;
        for (int i = 0;i < s.length();i++) {
            if (s[i] - 'a' <= k) {
                mxc = max(mxc, s[i] - 'a');
                continue;
            }
            if (mxc <= k) {
                for (int j = 1;j <= mxc;j++) {
                    to[j] = 0;
                }
                k -= mxc;
                mxc = 0;
            }
            if (k != 0 && mxc == 0) {
                for (int j = 1;j <= s[i] - 'a';j++) {
                    to[j] = min(to[j], s[i] - 'a' - k);
                }
                k = 0;
            }

        }
        if (mxc != 0) {
            for (int j = 1;j <= mxc;j++) {
                to[j] = 0;
            }
            k -= mxc;
            mxc = 0;
        }
        for (int i = 0;i < n;i++) {
            if (to[s[i] - 'a'] != 99 && to[s[i] - 'a'] < s[i] - 'a') {
                cout << (char)('a' + to[s[i] - 'a']);
            }
            else {
                cout << s[i];
            }
        }
        cout << "\n";
    }
    return 0;
}