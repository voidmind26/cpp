#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 10;


int w[N];
int er[N];
int ti[N];
bool vis[N];
int n, m;
int lis[N];
int ans = 0;

void solve() {
    int t = 0;
    int tmp = 0;
    for (int i = 1;i <= n;i++) {
        t += ti[lis[i]];
        if (t > m) {
            break;
        }
        int sor = w[lis[i]] - w[lis[i]] * 4 / 1000 * t - er[lis[i]] * 50;
        if (sor <= w[lis[i]] * 30 / 100)
            tmp += w[lis[i]] * 30 / 100;
        else {
            tmp += sor;
        }
    }
    ans = max(ans, tmp);
}

void dfs(int s, int d) {
    vis[s] = 1;
    lis[d] = s;
    if (d == n) {
        solve();
        vis[s] = 0;
        // for(int i=1;i<=n;i++){
        //     cout<<lis[i]<<" ";
        // }
        // cout<<endl;
        return;
    }
    for (int i = 1;i <= n;i++) {
        if (!vis[i]) {
            dfs(i, d+1);
        }
    }
    vis[s] = 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(vis, 0, sizeof(vis));
        ans = 0;
        cin >> n >> m;
        for (int i = 1;i <= n;i++) {
            cin >> w[i] >> ti[i] >> er[i];
        }
        for (int i = 1;i <= n;i++) {
            dfs(i, 1);
        }
        cout << ans << endl;
    }
    return 0;
}