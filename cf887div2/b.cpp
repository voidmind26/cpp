#include<iostream>

using namespace std;

#define int long long

const int N = 2e5 + 2;
int fb[N];

void init() {
    fb[1] = 1;
    fb[2] = 1;
    for (int i = 3;i <= N;i++) {
        if (fb[i - 1] == -1) {
            fb[i] = -1;
            continue;
        }
        fb[i] = fb[i - 1] + fb[i - 2];
        if (fb[i] > 1e9 + 1) {
            fb[i] = -1;
        }
    }
}


signed main() {
    int t;
    init();
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k > N) {
            cout << 0 << endl;
            continue;
        }
        int ta = fb[k - 2];
        int tb = fb[k - 1];
        if (tb > n) {
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        for (int i = 0;i * ta <= n;i++) {
            if ((n - i * ta) % tb == 0) {
                if ((n - i * ta) / tb < i) {
                    break;
                }
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}