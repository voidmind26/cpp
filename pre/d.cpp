#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
vector<int>a;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        a.clear();
        int n, l, r;
        cin >> n >> l >> r;
        for (int i = 0;i < n;i++) {
            int t;
            cin >> t;
            a.push_back(t);
        }
        int ans = 0;
        sort(a.begin(), a.end());
        for (int i = 0;i < n;i++) {
            int lpos = lower_bound(a.begin(), a.end(), l-a[i]) - a.begin();
            int rpos = upper_bound(a.begin(), a.end(), r - a[i]) - a.begin();
            if (i<lpos || i>=rpos) {
                ans += rpos - lpos;
            }
            else {
                ans += rpos - lpos - 1;
            }
            // cout << lpos << " " << rpos << endl;
            // cout << ans << endl;
        }
        cout << ans/2 << endl;
    }

    return 0;
}