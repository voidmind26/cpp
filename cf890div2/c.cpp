#include<iostream>

using namespace std;
const int N = 1002;
int n, k;
int a[N];
int b[N];
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int mx = 0;
        int pos = 0;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            if (a[i] > mx) {
                mx = a[i];
                pos = i;
            }

        }
        int ans = mx;
        //p1
        if (pos != 1) {
            int tk;
            int i = pos;
            tk = k;
            for (int j = 1;j <= pos;j++) {
                b[j] = a[j];
            }
            for (int j = i - 1;j >= 1;j--) {
                if (b[j] <= b[j + 1]) {
                    int tmp = b[j + 1] + 1 - b[j];
                    if (tmp > tk) {
                        b[j] += tk;
                        tk = 0;
                    }
                    else {
                        b[j] = b[j + 1] + 1;
                        tk -= tmp;
                    }
                }
                ans = max(ans, b[j]);
                if (tk == 0) {
                    break;
                }
            }

        }
        //p2
        if (pos != n) {
            int tk;
            tk = k;
            for (int j = 1;j <= n;j++) {
                b[j] = a[j];
            }
            for (int i = pos + 1;i <= n;i++) {
                if (b[i] > b[pos] - i + pos) {
                    for (int j = i - 1;j >= pos;j--) {
                        if (b[j] <= b[j + 1]) {
                            int tmp = b[pos] - i + pos - b[j];
                            if (tmp > tk) {
                                b[j] += tk;
                                tk = 0;
                            }
                            else {
                                b[j] += tmp;
                                tk -= tmp;
                            }
                        }
                        ans = max(ans, b[j]);
                        if (tk == 0) {
                            break;
                        }
                    }
                    if (tk == 0) break;
                    else {
                        if (tk > (b[i] - (b[pos] - i + pos)) * (i - pos)) {
                            tk -= (b[i] - (b[pos] - i + pos)) * (i - pos);
                            for (int j = i - 1;j >= pos;j--) {
                                b[j] = b[j + 1] + 1;
                                ans = max(ans, b[j]);
                            }
                        }
                        else {
                            ans = max(ans, b[pos] + tk / (i - pos));
                        }
                    }
                }
            }
            if (pos != 1) {
                int i = pos;
                for (int j = i - 1;j >= 1;j--) {
                    if (b[j] <= b[j + 1]) {
                        int tmp = b[j + 1] + 1 - b[j];
                        if (tmp > tk) {
                            b[j] += tk;
                            tk = 0;
                        }
                        else {
                            b[j] = b[j + 1] + 1;
                            tk -= tmp;
                        }
                    }
                    ans = max(ans, b[j]);
                    if (tk == 0) {
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}