#include<iostream>

using namespace std;
const int N = 505;
int a[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 1e9 + 5;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        for (int i = 2;i <= n;i++) {
            if (a[i] < a[i - 1]) {
                ans = 0;
                break;
            }
            if (a[i] == a[i - 1]) {
                ans = 1;
            }
            else {
                ans = min(ans, (a[i] - a[i - 1]) / 2 + 1);

            }
        }
        cout << ans << endl;
    }
    return 0;
}