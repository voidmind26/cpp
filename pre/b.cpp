#include<algorithm>
#include<iostream>
#define int long long
using namespace std;

const int N = 55;
int a[N];
int b[N];

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int min1 = 0x7fffffff;
        int min2 = 0x7fffffff;
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            min1 = min(a[i], min1);
        }
        for (int i = 1;i <= n;i++) {
            cin >> b[i];
            min2 = min(b[i], min2);
        }
        int ans = 0;
        for (int i = 1;i <= n;i++) {
            int ta = a[i] - min1;
            int tb = b[i] - min2;
            ans += max(ta, tb);
        }
        cout << ans << endl;
    }
    return 0;
}