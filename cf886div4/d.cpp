#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e5 + 1;
int a[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        int mx = 0;
        int tmp = 1;
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        for (int i = 2;i <= n;i++) {
            if (a[i] - a[i - 1] > k) {
                mx = max(mx, tmp);
                tmp = 1;
            }
            else {
                tmp++;
            }
        }
        mx = max(mx, tmp);
        tmp = 1;
        cout << n - mx << endl;
    }
    return 0;
}