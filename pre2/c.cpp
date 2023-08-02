#include<iostream>
#include<map>
#include<cstdio>
#define int long long


using namespace std;
int n, c;
map<int, int>hs;

signed main() {
    cin >> n >> c;
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
        if (hs.find(c + i.first) != hs.end()) {
            if (c + i.first == i.first) 
                ans += i.second / 2;
            else
                ans += i.second * hs[c + i.first];
        }
    }
    cout << ans << endl;
    return 0;
}