#include<bits/stdc++.h>

using namespace std;

map<int, vector<int> >ans;

const int N = 2e5 + 1;
struct Edge {
    int to, next;
}edge[N << 1];

int head[N];
int num;
int mxlen[N];
int fa[N];
bool vis[N];

void addedge(int u, int v) {
    edge[num].to = v;
    edge[num].next = head[u];
    head[u] = num++;
}

void dfs(int s) {
    vis[s] = 1;
    int mx = 0;
    int mxnum = 0;
    for (int p = head[s];~p;p = edge[p].next) {
        int v = edge[p].to;
        if (!vis[v]) {
            dfs(v);
            if (mx < mxlen[v]) {
                mx = mxlen[v];
                mxnum = v;
            }
        }
    }
    if (mx == 0) {
        ans[s].push_back(s);
    }
    else {
        fa[s] = fa[mxnum];
        ans[fa[s]].push_back(s);
    }
    mxlen[s] = mx + 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ans.clear();
        num = 0;
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            head[i] = -1;
            vis[i] = 0;
            mxlen[i] = 0;
            fa[i] = i;
        }
        int rt = -1;
        for (int i = 1;i <= n;i++) {
            int t;
            cin >> t;
            if (t == i) {
                rt = t;
                continue;
            }
            addedge(i, t);
            addedge(t, i);
        }
        dfs(rt);
        cout << ans.size() << "\n";
        for (auto i : ans) {
            cout << i.second.size() << "\n";
            for (int j = i.second.size() - 1;j >= 0;j--) {
                cout << i.second[j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}