#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        bool ok = 1;
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
        if (a < x) {
            if (c >= (x - a))
                c -= (x - a);
            else
                ok = 0;
        }
        if (!ok) {
            cout << "No\n";
            continue;
        }
        if (b < y) {
            if (c >= (y - b))
                c -= (y - b);
            else
                ok = 0;
        }
        if (!ok) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
    }


    return 0;
}