#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
struct Edge {
    int next, to;
}edge[N << 1];

bool vis[N];
int incle[N];
int head[N];
int disa[N];
int disb[N];
int n, a, b, num;
bool getcle;
bool yes;
struct node {
    int cur, dis;

    node() {}

    node(int a, int b) :cur(a), dis(b) {}
};

queue<node>q;


void addedge(int x, int y) {
    edge[num].to = y;
    edge[num].next = head[x];
    head[x] = num++;
}

void dfs(int s, int f) {
    vis[s] = 1;
    for (int p = head[s];~p;p = edge[p].next) {
        int to = edge[p].to;
        if (!vis[to]) {
            dfs(to, s);
            if (incle[to] != 0 && !getcle) {
                if (incle[s] != n + 1) {
                    incle[s] = incle[to] + 1;
                    return;
                }
                else {
                    incle[s] = incle[to] + 1;
                    getcle = 1;
                    return;
                }
            }
        }
        else {
            if (to != f) {
                incle[to] = n + 1;
                incle[s] = 1;
                return;
            }
        }
    }
}

void bfs1(int s) {
    vis[s] = 1;
    q.push(node(s, 0));
    while (!q.empty()) {
        node c = q.front();
        int cur = c.cur;
        disa[cur] = c.dis;
        q.pop();
        for (int p = head[cur];~p;p = edge[p].next) {
            int to = edge[p].to;
            if (!vis[to]) {
                q.push(node(to, c.dis + 1));
                vis[to] = 1;
            }
        }
    }
}

void bfs2(int s) {
    vis[s] = 1;
    q.push(node(s, 0));
    while (!q.empty()) {
        node c = q.front();
        int cur = c.cur;
        disb[cur] = c.dis;
        q.pop();
        for (int p = head[cur];~p;p = edge[p].next) {
            int to = edge[p].to;
            if (!vis[to]) {
                q.push(node(to, c.dis + 1));
                vis[to] = 1;
            }
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
        cin >> n >> a >> b;
        for (int i = 1;i <= n;i++) {
            incle[i] = 0;
            head[i] = -1;
            vis[i] = 0;
        }
        for (int i = 1;i <= n;i++) {
            int x, y;
            cin >> x >> y;
            addedge(x, y);
            addedge(y, x);
        }
        getcle = 0;
        dfs(b, 0);
        if (a == b) {
            cout << "NO" << endl;
            continue;
        }
        if (incle[b] != 0) {
            cout << "YES" << endl;
        }
        else {
            for (int i = 1;i <= n;i++) {
                vis[i] = 0;
            }
            bfs1(b);
            for (int i = 1;i <= n;i++) {
                vis[i] = 0;
            }
            bfs2(a);
            bool yess = 0;
            for (int i = 1;i <= n;i++) {
                if (incle[i] != 0) {
                    if (disa[i] < disb[i]) {
                        yess = 1;
                        break;
                    }
                }
            }
            if (yess) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}