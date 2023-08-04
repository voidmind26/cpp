#include<iostream>
#include<map>
#define int long long
using namespace std;
const int N = 2e5 + 1;
map<int, int>x;
map<int, int>y;
map<int, int>xpy;
map<int, int>xmy;
int jc[N];
void init() {
    for (int i = 3;i < N;i++) {
        jc[i] = jc[i - 1] + i - 1;
    }
}
signed main() {
    jc[2] = 1;
    init();
    int t;
    cin >> t;
    while (t--) {
        x.clear();
        y.clear();
        xpy.clear();
        xmy.clear();
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            int tx, ty;
            cin >> tx >> ty;
            x[tx]++;
            y[ty]++;
            xpy[tx + ty]++;
            xmy[tx - ty]++;
        }
        int ans = 0;
        for (auto i : x) {
            if (i.second >= 2) {
                ans += jc[i.second];
            }
        }
        for (auto i : y) {
            if (i.second >= 2) {
                ans += jc[i.second];
            }
        }
        for (auto i : xpy) {
            if (i.second >= 2) {
                ans += jc[i.second];
            }
        }
        for (auto i : xmy) {
            if (i.second >= 2) {
                ans += jc[i.second];
            }
        }
        cout << ans * 2 << endl;
    }
    return 0;
}