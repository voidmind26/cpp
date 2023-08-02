#include<iostream>
#include<queue>

using namespace std;
const int N = 1e4 + 1;
int n, m, s, t;
int f[N];
int ans = 0;

struct Edge {
    int u, v, w;

    Edge() {}

    Edge(int x, int y, int z) :u(x), v(y), w(z) {}

    bool operator <(const Edge& T)const {
        return w > T.w;
    }
};

priority_queue<Edge>pq;

int findfa(int x) {
    if (f[x] == x) {
        return x;
    }
    else {
        return f[x] = findfa(f[x]);
    }
}

void init() {
    for (int i = 1;i <= n;i++) {
        f[i] = i;
    }
}

int main() {
    cin >> n >> m >> s >> t;
    init();
    for (int i = 1;i <= m;i++) {
        int x, y, w;
        cin >> x >> y >> w;
        pq.push(Edge(x, y, w));
    }
    while (!pq.empty()) {
        if (findfa(s) == findfa(t)) {
            break;
        }
        Edge cur = pq.top();
        pq.pop();
        int u = cur.u;
        int v = cur.v;
        if (findfa(u) != findfa(v)) {
            f[findfa(v)] = findfa(u);
            ans = max(ans, cur.w);
        }
    }
    cout << ans << endl;
    return 0;
}