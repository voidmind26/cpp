#include<iostream>
#include<string>
using namespace std;
const int N = 5005;
int dp[N][N];
string a, b;

int main() {
    while (cin >> a) {
        cin >> b;
        int l1 = a.length();
        int l2 = b.length();
        for (int i = 1;i <= l1;i++) {
            for (int j = 1;j <= l2;j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        cout << dp[l1][l2] << endl;
    }
    return 0;
}