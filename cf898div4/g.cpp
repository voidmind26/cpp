#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;

int forward1[N];
int back1[N];
int dp[N][2];

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        int num = 0;
        int flag = 0;
        int cnt = 0;
        for (int i = 0;i < a.length();i++) {
            if (a[i] == 'B') {
                num++;
            }
        }
        for (int i = 0;i < a.length();i++) {
            if (a[i] == 'A') {
                flag++;
            }
            else {
                forward1[cnt++] = flag;
                flag = 0;
            }
        }
        flag = 0;
        cnt = 0;
        for (int i = a.length() - 1;i >= 0;i--) {
            if (a[i] == 'A') {
                flag++;
            }
            else {
                back1[num - cnt - 1] = flag;
                cnt++;
                flag = 0;
            }
        }

        if (num == 0) {
            cout << 0 << endl;
            continue;
        }
        for (int i = 0;i < num;i++) {
            if (i == 0) {
                dp[i][0] = forward1[i];
                dp[i][1] = back1[i];
            }
            else {
                dp[i][0] = dp[i - 1][0] + forward1[i];
                dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + back1[i];
            }
        }
        cout << max(dp[num - 1][0], dp[num - 1][1]) << endl;
    }
    return 0;
}