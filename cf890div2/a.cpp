#include<iostream>
#include<algorithm>
using namespace std;
const int N = 55;
int a[N];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        bool flag = 0;
        int ans = a[1];
        for (int i = n;i >= 2;i--) {
            if (flag)
                ans = max(ans, a[i]);
            if (a[i] < a[i - 1]) {
                flag = 1;
            }
        }
        if (!flag) {
            cout << 0 << endl;
        }
        else {
            cout << ans << endl;
        }
    }
    return 0;
}