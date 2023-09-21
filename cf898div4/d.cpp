#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string a;
        cin >> a;
        int ans = 0;
        int flag = 0;
        for (int i = 0;i < n;i++) {
            if (a[i] == 'B') {
                flag++;
            }
            else {
                if (flag != 0) {
                    flag++;
                }
            }
            if (flag >= k) {
                flag = 0;
                ans++;
            }
        }
        if (flag != 0) {
            flag = 0;
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}