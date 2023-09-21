#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N = 10002;
const int M = 200002;

struct Edge {
    int to;
    int next;
};

struct node {
    int cur;
    int time;

    node(int a, int b):cur(a), time(b) {}
    node() {}
};

Edge edge1[M];
Edge edge2[M];

int head1[N];
int head2[N];
int cnt = 0;

bool vis1[N];
bool vis2[N];

queue<int>q;
queue<node>q2;

int n, m;
int s, e;
bool got;

void add1(int x, int y) {
    edge1[cnt].to = y;
    edge1[cnt].next = head1[x];
    head1[x] = cnt++;
}

void add2(int x, int y) {
    cnt--;
    edge2[cnt].to = y;
    edge2[cnt].next = head2[x];
    head2[x] = cnt++;
}

void bfs1() {
    q.push(e);
    vis2[e] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int p = head2[u];~p;p = edge2[p].next) {
            int v = edge2[p].to;
            if (!vis2[v]) {
                vis2[v] = 1;
                q.push(v);
            }
        }
    }
}

void bfs2() {
    if (vis1[s]) {
        return;
    }
    vis1[s] = 1;
    q2.push(node(s, 0));
    while (!q2.empty()) {
        int u = q2.front().cur;
        int t = q2.front().time;
        q2.pop();
        if (u == e) {
            got = 1;
            cout << t << endl;
            return;
        }
        for (int p = head1[u];~p;p = edge1[p].next) {
            int v = edge1[p].to;
            if (!vis1[v]) {
                vis1[v] = 1;
                q2.push(node(v, t + 1));
            }
        }
    }
}

int main() {
    memset(head1, -1, sizeof(head1));
    memset(head2, -1, sizeof(head2));
    cin >> n >> m;

    for (int i = 1;i <= m;i++) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            continue;
        }
        add1(x, y);
        add2(y, x);
    }

    cin >> s >> e;
    bfs1();

    for (int i = 1; i <= n; i++) {
        if (vis2[i] == 0) {
            vis1[i] = 1;
            for (int p = head2[i];~p;p = edge2[p].next) {
                int v = edge2[p].to;
                vis1[v] = 1;
            }
        }
    }

    bfs2();
    if (!got) {
        cout << -1 << endl;
    }
    return 0;
}