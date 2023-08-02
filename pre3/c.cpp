#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

const int M = 5e4 + 1;
const int N = 1e4 + 1;
const int Level = 19;
const int oo = 0x7fffffff;
struct Edge {
    int to, next, w;


}edge[M << 1];

struct node {

    int u, v, w;

    node() {}

    node(int a, int b, int c) :u(a), v(b), w(c) {}

    bool operator < (const node& T)const {
        return w < T.w;
    }
};


int head[N], fa[N], deep[N], ant[N][19], minw[N][19];
bool vis[N];
int n, m, q, num;
priority_queue<node>pq;

void addedge(int x, int y, int w) {
    edge[num].to = y;
    edge[num].w = w;
    edge[num].next = head[x];
    head[x] = num++;
}

void init() {
    for (int i = 1;i <= n;i++) {
        fa[i] = i;
    }
    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));
    for (int i = 0;i <= n;i++) {
        for (int j = 0;j < Level;j++) {
            minw[i][j] = oo;
        }
    }
    deep[0] = -1;
}

int findfa(int x) {
    if (fa[x] == x) {
        return x;
    }
    else {
        return fa[x] = findfa(fa[x]);
    }
}

void mst() {
    while (!pq.empty()) {
        node cur = pq.top();
        pq.pop();
        int k1 = findfa(cur.u);
        int k2 = findfa(cur.v);
        if (k1 != k2) {
            fa[findfa(k2)] = findfa(k1);
            addedge(cur.u, cur.v, cur.w);
            addedge(cur.v, cur.u, cur.w);
        }
    }
}

void dfs(int root, int f) {
    deep[root] = deep[f] + 1;
    vis[root] = 1;
    for (int p = head[root];~p;p = edge[p].next) {
        int t = edge[p].to;
        if (!vis[t]) {
            ant[t][0] = root;
            minw[t][0] = edge[p].w;
            dfs(t, root);
        }
    }
}

void lcainit() {
    for (int i = 1;i < Level;i++) {
        for (int j = 1;j <= n;j++) {
            ant[j][i] = ant[ant[j][i - 1]][i - 1];
        }
    }
    for (int i = 1;i < Level;i++) {
        for (int j = 1;j <= n;j++) {
            minw[j][i] = min(minw[j][i - 1], minw[ant[j][i - 1]][i - 1]);
        }
    }
}

int lca(int x, int y) {
    if (findfa(x) != findfa(y))return -1;
    if (deep[x] < deep[y])swap(x, y);
    int ansx = oo;
    int ansy = oo;
    for (int i = Level - 1;i >= 0;i--) {
        if (deep[ant[x][i]] >= deep[y]) {
            ansx = min(ansx, minw[x][i]);
            x = ant[x][i];
        }
    }
    if (x == y) {
        return ansx;
    }
    for (int i = Level - 1;i >= 0;i--) {
        if (ant[y][i] != ant[x][i]) {
            ansx = min(ansx, minw[x][i]);
            ansy = min(ansy, minw[y][i]);
            x = ant[x][i];
            y = ant[y][i];
            //  cout << x << " " << y << " " << ansx <<" "<<ansy<< endl;
        }
    }
    ansx = min(ansx, minw[x][0]);
    ansy = min(ansy, minw[y][0]);
    return min(ansy, ansx);
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x, y, w;
        cin >> x >> y >> w;
        pq.push(node(x, y, w));
    }
    init();
    mst();
    for (int i = 1;i <= n;i++) {
        if (!vis[i]) {
            deep[i] = 1;
            dfs(i, i);
            ant[i][0] = i;
            minw[i][0] = oo;
        }
    }
    lcainit();

    cin >> q;
    for (int i = 1;i <= q;i++) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }

    return 0;
}

/*

*/