#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
const int N = 155;
struct Edge {
    int to, next;
}edge[10004];
int num[N], low[N], n, m, t;
int head[N];
int cnt;
vector<pair<int, int>>ans;

void addedge(int x, int y) {
    edge[cnt].to = y;
    edge[cnt].next = head[x];
    head[x] = cnt++;
}

void dfs(int u, int fa) {
    num[u] = low[u] = t++;
    int child = 0;
    for (int p = head[u];~p;p = edge[p].next) {
        int v = edge[p].to;
        if (!num[v]) {
            child++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (num[v] >= low[u] && u != 1) {
                ans.push_back(pair(u, v));
            }
        }
        else if (v != fa && num[v] < num[u]) {
            
        }
    }
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x, y;
        cin >> x >> y;
        addedge(x, y);
        addedge(y, x);
    }
    t = 1;
    dfs(1, 1);
    for (auto i : ans) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}