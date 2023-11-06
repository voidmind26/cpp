#include<bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;
    while (k--) {
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        bool flag1 = 1;
        bool f1hv1 = 0, f1hv0 = 0;
        for (int i = 0;i < n - 1;i++) {
            if (s[i] == s[i + 1]) {
                flag1 = 0;
                if (s[i] == '0') {
                    f1hv0 = 1;
                }
                else {
                    f1hv1 = 1;
                }
            }
        }
        bool flag2 = 1;
        bool f2hv1 = 0, f2hv0 = 0;
        for (int i = 0;i < m - 1;i++) {
            if (t[i] == t[i + 1]) {
                flag2 = 0;
                break;
            }
        }
        if (t[0] == t[t.length() - 1]) {
            if (t[0] == '0') {
                f2hv0 = 1;
            }
            else {
                f2hv1 = 1;
            }
        }
        if (flag1 == 1) {
            cout << "Yes\n";
        }
        else {
            if (flag2 == 0) {
                cout << "No\n";
            }
            else if (f1hv0 && f1hv1) {
                cout << "No\n";
            }
            else if (f1hv0) {
                if (f2hv1) {
                    cout << "Yes\n";
                }
                else {
                    cout << "No\n";
                }
            }
            else {
                if (f2hv0) {
                    cout << "Yes\n";
                }
                else {
                    cout << "No\n";
                }
            }
        }
    }
    return 0;
}