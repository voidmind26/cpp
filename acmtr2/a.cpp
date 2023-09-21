#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


#define double long double
#define pi 3.1415926535897932384626433832795028841971
const int N = 1e6 + 1;
double a[N];
int ans[N << 1];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            double x, y;
            cin >> x >> y;
            if (x > 0) {
                if (y <= 0) {
                    a[i] = acos(x / sqrt(x * x + y * y));
                }
                else {
                    a[i] = 2 * pi - acos(x / sqrt(x * x + y * y));
                }
            }
            else {
                if (y <= 0) {
                    a[i] = acos(x / sqrt(x * x + y * y));
                }
                else {
                    a[i] = 2 * pi - acos(x / sqrt(x * x + y * y));
                }
            }
            ans[i] = n + 1;
        }
        sort(a + 1, a + 1 + n);


        for (int i = 1;i <= n;i++) {
            a[n + i] = a[i] + 2 * pi;
        }
        int r = 1;
        for (int i = 1;i <= n;i++) {
            while (1) {
                if (a[r] - a[i] > pi) {
                    break;
                }
                r++;
            }
            if (i == 1 && r > n) {
                ans[i] = 0;
                break;
            }
            if (ans[i] != n + 1) {
                break;
            }
            ans[i] = r - i - 1;
            ans[r - 1] = n - r + i + 1;
        }
        int out = n + 1;

        for (int i = 1;i <= n;i++) {
            out = min(out, ans[i]);
        }
        cout << out << endl;
    }

    return 0;
}

/*
1
3
1 0
0 1
-1 -1
5
2 -1
1 2
-1 2
-2 -1
0 -2

*/