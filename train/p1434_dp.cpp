#include<iostream>

using namespace std;

const int N = 101;
int a[N][N];
int dp[N][N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> a[i][j];
            dp[i][j] = 1;
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (i == 1) {

            }

        }
    }

    return 0;
}