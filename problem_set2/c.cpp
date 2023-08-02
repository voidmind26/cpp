#include<iostream>
#include<map>

using namespace std;

map<int, int>hs;

int main() {
    int t;
    cin >> t;
    while (t--) {
        hs.clear();
        int n, k;
        cin >> n >> k;
        for (int i = 1;i <= n;i++) {
            int t;
            cin >> t;
            if (hs.find(t) == hs.end()) {
                hs[t] = 1;
            }
            else {
                hs[t]++;
            }
        }
        int ans = 0;
        for (auto i : hs) {
            if (i.first % k == 0) {
                if (i.second < hs[i.first / k]) {
                    hs[i.first] = 0;
                    hs[i.first / k] -= i.second;
                }
                else {
                    hs[i.first] -= hs[i.first / k];
                    hs[i.first / k] = 0;
                }
            }

        }
        for (auto i : hs) {
            if (i.second != 0) {
                ans += i.second;
            }
        }
        cout << ans << endl;

    }
    return 0;
}