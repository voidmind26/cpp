#include<iostream>
#include<queue>
#include<cstring>
#define int long long
using namespace std;

const int N = 1e4 + 1;
const int M = 5e4 + 1;
const int oo = 0x7fffffff;

struct Edge {
    int to, next, w;
}edge[M << 1];

struct node {
    int v, dist;

    node() {}

    node(int x, int y) :v(x), dist(y) {}

    bool operator < (const node& T)const {
        return dist > T.dist;
    }
};

priority_queue<node>pq;
bool vis[N];
int n, m, h, num;
int fi[N], head[N], dist[N];

void add(int u, int v, int w) {
    edge[num].to = v;
    edge[num].next = head[u];
    edge[num].w = w;
    head[u] = num++;
}

void init() {
    while (!pq.empty()) {
        pq.pop();
    }
    for (int i = 1;i <= n;i++) {
        dist[i] = oo;
        vis[i] = 0;
    }                          
}

bool check(int x) {
    init();
    dist[1] = 0;
    if (fi[1] > x) {
        return 0;
    }
    pq.push(node(1, 0));
    while (!pq.empty()) {
        node cur = pq.top();
        pq.pop();
        int u = cur.v;
        vis[u] = 1;
        for (int p = head[u];~p;p = edge[p].next) {
            int v = edge[p].to;
            if (dist[u] + edge[p].w < dist[v] && !vis[v] && fi[v] <= x) {
                dist[v] = edge[p].w + dist[u];  
                pq.push(node(v, dist[u] + edge[p].w));
            }
        }
    }
    if (dist[n] <= h) {
        return 1;
    }
    else {
        return 0;
    }
}

int solve(int l, int r) {
    if (l >= r) {
        return l;
    }
    int mid = (l + r) / 2;
    if (check(mid)) {
        return solve(l, mid);
    }
    else {
        return solve(mid + 1, r);
    }
}

signed main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m >> h;
    for (int i = 1;i <= n;i++) {
        cin >> fi[i];
    }
    for (int i = 1;i <= m;i++) {
        int x, y, w;
        cin >> x >> y >> w;
        add(x, y, w);
        add(y, x, w);
    }

    int res = solve(fi[1], 2e9 + 1);
    if (res == 2e9 + 1) {
        cout << "AFK" << endl;
    }
    else {
        cout << res << endl;
    }

    return 0;
}