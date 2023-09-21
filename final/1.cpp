#include<iostream>
#include<algorithm>
using namespace std;
int it[1000];
int main() {
    int n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;

    for (int i = 1;i <= n + m;i++) {
        if (i <= n) {
            it[i % k] += x;
        }
        else {
            it[i % k] += y;
        }
    }
    int ans = -1;
    for (int i = 0;i < k;i++) {
        if (ans < it[i]) {
            ans = it[i];
        }
    }
    cout << ans << endl;
    return 0;
}