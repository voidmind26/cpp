#include<bits/stdc++.h>

using namespace std;

map<string, int> hsh[1001];

vector<int> grp[1001];

bool mark[1001];
bool vis[1001];
int num = 0;
int ans = 0;

void dfs(int rt) {
    if (!mark[rt]) {
        ans++;
        return;
    }
    vis[rt] = 1;
    for (auto i : grp[rt]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        num = 0;
        ans = 0;
        cin >> n >> m;
        for (int i = 0; i <= 1000; i++) {
            hsh[i].clear();
            mark[i] = 0;
            vis[i] = 0;
            grp[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            string tmp;
            cin >> tmp;
            int cur = 0;
            int last = 0;
            for (int j = 0; j < tmp.length(); j++) {
                if (tmp[j] == '/') {
                    string inp = tmp.substr(last, j - last);
                    last = j + 1;
                    if (hsh[cur].find(inp) == hsh[cur].end()) {
                        hsh[cur][inp] = ++num;
                        grp[cur].push_back(hsh[cur][inp]);
                    }
                    for (auto k : grp[cur]) {
                        if (k == hsh[cur][inp]) {
                            cur = hsh[cur][inp];
                            break;
                        }
                    }
                }
            }
            string inp = tmp.substr(last, tmp.length() - last);
            if (hsh[cur].find(inp) == hsh[cur].end()) {
                hsh[cur][inp] = ++num;
                grp[cur].push_back(hsh[cur][inp]);
            }
            for (auto k : grp[cur]) {
                if (k == hsh[cur][inp]) {
                    cur = hsh[cur][inp];
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            string tmp;
            cin >> tmp;
            int cur = 0;
            int last = 0;
            for (int j = 0; j < tmp.length(); j++) {
                if (tmp[j] == '/') {
                    string inp = tmp.substr(last, j - last);
                    last = j + 1;
                    if (hsh[cur].find(inp) == hsh[cur].end()) {
                        hsh[cur][inp] = ++num;
                        grp[cur].push_back(hsh[cur][inp]);
                    }
                    for (auto k : grp[cur]) {
                        if (k == hsh[cur][inp]) {
                            cur = hsh[cur][inp];
                            break;
                        }
                    }
                    mark[cur] = 1;
                }
            }
            string inp = tmp.substr(last, tmp.length() - last);
            if (hsh[cur].find(inp) == hsh[cur].end()) {
                hsh[cur][inp] = ++num;
                grp[cur].push_back(hsh[cur][inp]);
            }
            for (auto k : grp[cur]) {
                if (k == hsh[cur][inp]) {
                    cur = hsh[cur][inp];
                    break;
                }
            }
            mark[cur] = 1;
        }
        mark[0] = 1;
        dfs(0);
        cout << ans << "\n";
    }

    return 0;
}