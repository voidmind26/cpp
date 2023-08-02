#include<iostream>

using namespace std;
const int N = 5001;
int a[N];
int dp[N];
int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        for (int j = i - 1;j >= 0;j--) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}