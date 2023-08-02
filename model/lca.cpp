#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 5e5 + 2;
const int Level = 19;
int head[N], deep[N], anc[N][Level], vis[N];
int n, q, r, num;


struct Edge {
    int next;
    int to;
}edge[N << 1];

void addedge(int x, int y) {
    edge[num].to = y;
    edge[num].next = head[x];
    head[x] = num++;
}

void dfs(int root, int fa) {
    anc[root][0] = fa;
    deep[root] = deep[fa] + 1;
    vis[root] = 1;
    for (int p = head[root];~p;p = edge[p].next) {
        int t = edge[p].to;
        if (!vis[t]) {
            dfs(t, root);
        }
    }
}

void init() {
    for (int i = 1;i < Level;i++) {
        for (int j = 1;j <= n;j++) {
            anc[j][i] = anc[anc[j][i - 1]][i - 1];
        }
    }
}

int lca(int x, int y) {
    if (x == y) {
        return x;
    }
    if (deep[x] < deep[y]) {
        swap(x, y);
    }
    for (int i = Level - 1;i >= 0;i--) {
        if (deep[anc[x][i]] >= deep[y]) {
            x = anc[x][i];
        }

    }
    if (x == y) {
        return x;
    }

    for (int i = Level - 1;i >= 0;i--) {
        if (anc[x][i] != anc[y][i]) {
            x = anc[x][i];
            y = anc[y][i];
        }
    }
    return anc[x][0];
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> q >> r;
    for (int i = 1;i < n;i++) {
        int x, y;
        cin >> x >> y;
        addedge(x, y);
        addedge(y, x);
    }

    deep[0] = -1;
    anc[r][0] = r;
    dfs(r, r);
    init();

    for (int i = 1;i <= q;i++) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }

    return 0;
}