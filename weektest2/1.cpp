#include<iostream>
using namespace std;
const int N = 801;
int a[N][N];
int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1;i < n;i++) {
        for (int j = i + 1;j <= n;j++) {
            if (a[i][j] != a[j][i]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}