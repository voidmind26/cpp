#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        int n, a, q;
        string s;
        cin >> n >> a >> q;
        cin >> s;
        int num1 = a;
        int num2 = a;
        int mxnum1 = a;
        for (int i = 0;i < s.length();i++) {
            if (s[i] == '+') {
                num1 += 1;
                num2 += 1;
                mxnum1 = max(mxnum1, num1);
            }
            if (s[i] == '-') {
                num1--;
            }
        }
        if (mxnum1>= n) {
            cout << "YES" << endl;
        }
        else {
            if (num2 >= n) {
                cout << "MAYBE" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}