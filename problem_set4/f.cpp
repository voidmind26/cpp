#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 2005;
int k, n;
int c[N][N];
int sum[N][N];
int main() {
    cin >> n >> k;
    c[1][1] = 1;
    c[1][0] = 1;
    c[0][0] = 1;
    for (int i = 2;i <= N - 1;i++) {
        for (int j = 0;j <= i;j++) {
            if (j == 0) {
                c[i][j] = 1;
                continue;
            }
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
        }
    }
    sum[0][0] = 0;
    memset(sum, 0, sizeof(sum));
    for (int i = 1;i < N;i++) {
        for (int j = 0;j < N;j++) {
            if (i == 0) {
                if (c[i][j] == 0 && j <= i) {
                    sum[i][j] = sum[i][j - 1] + 1;
                }
                else {
                    sum[i][j] = sum[i][j - 1];
                }
            }
            else if (j == 0) {
                if (c[i][j] == 0 && j <= i)
                    sum[i][j] = sum[i - 1][j] + 1;
                else
                    sum[i][j] = sum[i - 1][j];
            }
            else {
                if (c[i][j] == 0 && j <= i)
                    sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + 1;
                else
                    sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
    }
    for (int i = 1;i <= n;i++) {
        int x, y;
        cin >> x >> y;
        if (y > x) {
            cout << sum[x][x] << endl;
        }
        else {
            cout << sum[x][y] << endl;
        }
    }
    return 0;
}