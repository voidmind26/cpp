#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 505;
char g[N][N];
char ans[N][N];
int row[N];
int col[N];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string a;
        for (int i = 1;i <= n;i++) {
            col[i] = 0;
            cin >> a;
            for (int j = 0;j < m;j++) {
                row[j] = 0;
                g[i][j + 1] = a[j];
            }
        }
        row[m] = 0;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                if (g[i][j] == '.') {
                    ans[i][j] = '.';
                    continue;
                }
                if (g[i][j] == 'L') {
                    if (row[j] <= 0) {
                        ans[i][j] = 'W';
                        ans[i][j + 1] = 'B';
                        row[j]++;
                        row[j + 1]--;
                    }
                    else {
                        ans[i][j] = 'B';
                        ans[i][j + 1] = 'W';
                        row[j]--;
                        row[j + 1]++;
                    }
                }
                if (g[i][j] == 'U') {
                    if (col[i] <= 0) {
                        ans[i][j] = 'W';
                        ans[i + 1][j] = 'B';
                        col[i]++;
                        col[i + 1]--;
                    }
                    else {
                        ans[i][j] = 'B';
                        ans[i + 1][j] = 'W';
                        col[i]--;
                        col[i + 1]++;
                    }
                }
            }
        }

        bool flag = 1;
        for (int i = 1;i <= n;i++) {
            if (col[i] != 0) {
                flag = 0;
                break;
            }
        }
        if (!flag) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1;i <= m;i++) {
            if (row[i] != 0) {
                flag = 0;
                break;
            }
        }
        if (!flag) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}