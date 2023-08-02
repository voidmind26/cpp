#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;
const int N = 1e6 + 1;
int ff[N];
int fa[N];
int hv[N];
int sz[N];
int pos[N];
int deep[N];
queue<int>q;
int ans = 0;
struct Edge {
    int to, next;
}edge[N << 1];
int hd[N];
vector<int>head;
int n, num;

void bfs() {
    q.push(1);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        if (s == 1) {
            head.push_back(s);
            fa[s] = s;
            sz[s] = 1;
        }
        else if (hv[ff[s]] != s) {
            head.push_back(s);
            fa[s] = s;
            sz[s] = 1;
        }
        else {
            fa[s] = fa[ff[s]];
            sz[fa[s]]++;
        }
        for (int p = hd[s];~p;p = edge[p].next) {
            q.push(edge[p].to);
        }
    }

}

void solve(int x) {
    if (ff[fa[x]] == 0) {
        deep[fa[x]] = ceil(log2((double)2 * sz[fa[x]]));
        return;
    }
    if (deep[fa[ff[fa[x]]]] != 0) {
        deep[fa[x]] = deep[fa[ff[fa[x]]]] + ceil(log2((double)2 * sz[fa[x]]));
        return;
    }
    solve(ff[fa[x]]);
}

void addedge(int x, int y) {
    edge[num].to = y;
    edge[num].next = hd[x];
    hd[x] = num++;
}

int main() {
    num = 0;
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        head.clear();
        cin >> n;
        for (int i = 0;i <= n;i++) {
            hd[i] = -1;
        }
        for (int i = 1;i <= n;i++) {
            cin >> ff[i];
            deep[i] = 0;
            sz[i] = 0;
            addedge(ff[i], i);
        }
        for (int i = 1;i <= n;i++) {
            cin >> hv[i];
        }
        bfs();
        for (auto i : head) {
            solve(i);
            ans = max(ans, deep[fa[i]]);
        }
        cout << ans << endl;
    }
    return 0;
}