#include<iostream>

using namespace std;

const int N = 1001;
int dp[N];
int a[7];
int hs[] = { 0,1,2,3,5,10,20 };

int main() {
    dp[0] = 1;
    for (int i = 1;i <= 6;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= 6;i++) {
        for (int j = 1;j <= a[i];j++) {
            for (int k = 1000;k >= 0;k--) {
                if (dp[k]) {
                    dp[k + hs[i]] = 1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1;i <= 1000;i++) {
        if (dp[i]) {
            ans++;
        }
    }
    cout << "Total=" << ans << endl;
    return 0;
}