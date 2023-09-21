#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define endl "\n"

const int N = 1e5 + 1;
map<int, int>save1;//x+y
map<int, int>save2;//x-y



signed main() {
    int n;
    while (cin >> n) {
        save1.clear();
        save2.clear();
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            if (save1.find(x + y) == save1.end()) {
                save1[x + y] = 1;
            }
            else {
                save1[x + y]++;
            }
            if (save2.find(x - y) == save2.end()) {
                save2[x - y] = 1;
            }
            else {
                save2[x - y]++;
            }
        }
        int cnt = 0;
        for (auto i : save1) {
            int t = i.second;
            if (t >= 2) {
                cnt += (t - 1) * t / 2;
            }
        }
        for (auto i : save2) {
            int t = i.second;
            if (i.second >= 2) {
                cnt += (t - 1) * t / 2;
            }
        }
        cnt *= 2;
        cout << (double)cnt / (double)n / (double)n << endl;
    }
    return 0;
}