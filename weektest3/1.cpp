#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;
struct Edge {
    int to, next;
}edge[N];

int num;
int head[N], vis[N], dep[N], fa[N], uplen[N], solved[N], du[N];
queue<int>q;

void addedge(int u, int v) {
    du[u]++;
    edge[num].to = v;
    edge[num].next = head[u];
    head[u] = num++;
}

void dfs(int s) {
    vis[s] = 1;
    bool flag = 1;
    for (int p = head[s];~p;p = edge[p].next) {
        int to = edge[p].to;
        if (!vis[to]) {
            dep[to] = dep[s] + 1;
            fa[to] = s;
            flag = 0;
            dfs(to);
        }
    }
    uplen[s] = dep[s];
    if (flag) {
        q.push(s);
    }
}

void ufs(int s) {
    if (fa[s] == s || solved[fa[s]]) {
        solved[s] = 1;
        return;
    }
    solved[s] = 1;
    ufs(fa[s]);
}

void upload(int s) {
    if (fa[s] == s || solved[fa[s]]) {
        uplen[s] = 1;
        return;
    }
    upload(fa[s]);
    uplen[s] = uplen[fa[s]] + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        num = 0;
        for (int i = 0;i <= n;i++) {
            vis[i] = 0;
            dep[i] = 0;
            uplen[i] = 0;
            solved[i] = 0;
            fa[i] = 0;
            du[i] = 0;
            head[i] = -1;
            while (!q.empty()) {
                q.pop();
            }

        }
        for (int i = 1;i < n;i++) {
            int tmp;
            cin >> tmp;
            addedge(tmp, i + 1);
        }
        dep[1] = 1;
        fa[1] = 1;
        dfs(1);
        int ans = 0;
        int st = 0;
        bool flag = 0;
        while (!q.empty()) {
            int cur = q.front();
            if (st == cur) {
                queue<int>tmp;
                while (!q.empty()) {
                    int curr = q.front();
                    du[fa[curr]]--;
                    if (du[fa[curr]] == 0) {
                        tmp.push(fa[curr]);
                    }
                    q.pop();
                }
                while (!tmp.empty()) {
                    q.push(tmp.front());
                    upload(tmp.front());
                    tmp.pop();
                }
                ans++;
                flag = 0;
                continue;
            }
            if (flag == 0) {
                st = cur;
                flag = 1;
            }
            q.pop();
            if (uplen[cur] > q.size() + 1) {
                ufs(cur);
                bool flag2 = 0;
                int nxt = -1;
                while (!q.empty() && 1) {
                    int curr = q.front();
                    q.pop();
                    if (curr == nxt) {
                        q.push(curr);
                        break;
                    }
                    if (!flag2) {
                        nxt = curr;
                        flag2 = 1;
                    }
                    upload(curr);
                    q.push(curr);
                }
                ans++;
                flag = 0;
            }
            else {
                q.push(cur);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}