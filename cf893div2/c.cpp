#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
const int N = 1e5 + 1;
int vis[N];
int gcdvis[N];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ans.clear();
        for (int i = 1;i <= n;i++) {
            vis[i] = 0;
            gcdvis[i] = 0;
        }
        gcdvis[1] = 1;
        ans.push_back(1);
        vis[1] = 1;
        for (int i = 2;i <= n;i++) {
            if (!vis[i]) {
                ans.push_back(i);
                vis[i] = 1;
                int tmp = i;
                while (tmp * 2 <= n) {
                    gcdvis[tmp] = 1;
                    vis[tmp * 2]=1;
                    ans.push_back(tmp * 2);
                    tmp *= 2;
                }
            }
        }
        // for (int i = 1;i <= n; i++) {
        //     if (!vis[i]) {
        //         ans.push_back(i);
        //         vis[i] = 1;
        //     }
        // }
        for (auto i : ans) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}