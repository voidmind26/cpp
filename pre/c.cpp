#include<iostream>
#include<queue>

using namespace std;
const int N = 2e5 + 1;
int a[N];
priority_queue<int, vector<int>, less<int> > save;

int main() {
    int t;
    cin >> t;
    while (t--) {
        while (!save.empty()) {
            save.pop();
        }
        int tmp1 = 0;
        int tmp2 = 0;
        int n;
        cin >> n;
        int a;
        for (int i = 1;i <= n;i++) {
            cin >> a;
            int ti = i;
            while (ti && ti % 2 == 0) {
                tmp1++;
                ti /= 2;
            }
            save.emplace(tmp1);
            tmp1 = 0;
            while (a && a % 2 == 0) {
                tmp2++;
                a /= 2;
            }
        }
        // cout << tmp2 << " " << sum << endl;
        if (tmp2 >= n) {
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        while (!save.empty()) {
            tmp2 += save.top();
            save.pop();
            ans++;
            if (tmp2 >= n) {
                break;
            }
        }
        if (tmp2 < n) {
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }

    return 0;
}