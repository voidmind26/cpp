#include<bits/stdc++.h>

using namespace std;

int point[10][10];

int main() {
    for (int i = 0;i < 10;i++) {
        for (int j = 0;j < 10;j++) {
            if (i == 0 || j == 0 || i == 9 || j == 9) {
                point[i][j] = 1;
            }
            else if (i == 1 || j == 1 || i == 8 || j == 8) {
                point[i][j] = 2;
            }
            else if (i == 2 || j == 2 || i == 7 || j == 7) {
                point[i][j] = 3;
            }
            else if (i == 3 || j == 3 || i == 6 || j == 6) {
                point[i][j] = 4;
            }
            else if (i == 4 || j == 4 || i == 5 || j == 5) {
                point[i][j] = 5;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        string a;
        for (int i = 0;i < 10;i++) {
            cin >> a;
            for (int j = 0;j < 10;j++) {
                if (a[j] == 'X') {
                    ans += point[i][j];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}