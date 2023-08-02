#include<iostream>
#include<algorithm>
using namespace std;

const int N = 4001;
const int M = 13000;
int w[N];
int r[N];
int dp[M];

int main() {
    int n, v;
    cin >> n >> v;
    for (int i = 1;i <= n;i++) {
        cin >> r[i] >> w[i];
    }
    for (int i = 1;i <= n;i++) {
        for (int j = v;j >= r[i];j--) {
            dp[j] = max(dp[j], dp[j - r[i]] + w[i]);
        }

    }
    cout << dp[v] << endl;
    return 0;
}