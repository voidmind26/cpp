#include<iostream>
#include<vector>

using namespace std;
const int N = 1001;
vector<int>p[101];
int r[N];
int w[N];
int dp[1001];


int main() {
    int n, v;
    int num = 0;
    cin >> v >> n;
    for (int i = 1;i <= n;i++) {
        int tmp;
        cin >> r[i] >> w[i] >> tmp;
        p[tmp].push_back(i);
    }
    for (int i = 1;i <= 100;i++) {
        for (int j = v;j >= 0;j--) {
            for (auto k : p[i]) {
                if (j - r[k] >= 0) {
                    dp[j] = max(dp[j], dp[j - r[k]] + w[k]);
                }
            }
        }
    }
    cout << dp[v] << endl;
    return 0;
}