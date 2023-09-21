#include<bits/stdc++.h>

using namespace std;

const int N = 100;
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
        int minn = 100;
        int minpos = 0;
        for (int i = 1;i <= n;i++) {
            if (a[i] < minn) {
                minn = a[i];
                minpos = i;
            }
        }
        a[minpos]++;
        int ans = a[1];
        for (int i = 2;i <= n;i++) {
            ans *= a[i];
        }
        cout << ans << endl;
    }
    return 0;
}