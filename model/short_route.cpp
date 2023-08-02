#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
#define int long long 
using namespace std;

const int N = 1e5 + 1;
const int M = 2e5 + 1;

struct node {
    int v, dist;

    node() {}

    node(int a, int b) :v(a), dist(b) {}

    bool operator < (const node& T)const {
        return dist > T.dist;
    }
};

struct Edge {
    int to;
    int next, w;
}edge[M << 1];

priority_queue<node>pq;

int n, m, s, dist[N], head[N], num;
bool vis[N];

void djs(int s) {
    for (int i = 1;i <= n;i++) {
        dist[i] = 0x7fffffff;
    }
    dist[s] = 0;
    pq.push(node(s, 0));
    while (!pq.empty()) {
        node cur = pq.top();
        pq.pop();
        int u = cur.v;
        if (!vis[u]) {
            vis[u] = 1;
        }
        else {
            continue;
        }
        for (int p = head[u];p != -1;p = edge[p].next) {
            int v = edge[p].to;
            int w = dist[u] + edge[p].w;
            if (dist[v] > w) {
                dist[v] = w;
                pq.push(node(v, w));
            }

        }
    }
}

void addedge(int u, int v, int w) {
    edge[num].to = v;
    edge[num].next = head[u];
    edge[num].w = w;
    head[u] = num++;
}

signed main() {
    // freopen("test.in", "r", stdin);
    memset(head, -1, sizeof(head));
    cin >> n >> m >> s;
    for (int i = 1;i <= m;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        addedge(x, y, z);
    }
    djs(s);
    for (int i = 1;i <= n;i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}