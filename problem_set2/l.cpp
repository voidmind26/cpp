#include<iostream>
#include<deque>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>

using namespace std;
const int N = 505;
const int M = 5e5 + 1;

int n, m, num, ans;
int dist[N * N];

struct edge {
    int to, w;

    edge() {}

    edge(int a, int b) :to(a), w(b) {}
};

struct node {
    int s, dist;
    node() {}
    node(int a, int b) :s(a), dist(b) {}
};
deque<node>dq;
vector<edge>mp[N * N];

int hscode(int x, int y) {
    return x * (m + 1) + y + 1;
}

void addedge(int x, int y, int w) {
    mp[x].push_back(edge(y, w));
}

int bfs() {
    dist[1] = 0;
    dq.push_front(node(1, 0));
    while (!dq.empty()) {
        node cur = dq.front();
        dq.pop_front();
        int u = cur.s;
        for (auto eg : mp[u]) {
            int v = eg.to;
            if (v == hscode(n, m)) {
                return cur.dist + eg.w;
            }
            int w = eg.w;
            if (dist[v] > dist[u] + w) {
                if (w == 0) {
                    dist[v] = dist[u] + w;
                    dq.push_front(node(v, cur.dist));
                }
                else {
                    dist[v] = dist[u] + w;
                    dq.push_back(node(v, cur.dist + w));
                }
            }
        }
    }
    return -1;
}

int main() {
    fill(dist, dist + N * N, 0x7fffffff);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        string tmp;
        cin >> tmp;
        for (int j = 1;j <= tmp.length();j++) {
            int x1 = hscode(i, j - 1); // '/'
            int y1 = hscode(i - 1, j);
            int x2 = hscode(i - 1, j - 1);//  '\'
            int y2 = hscode(i, j);
            if (tmp[j - 1] == '/') {
                addedge(x1, y1, 0);
                addedge(y1, x1, 0);
                addedge(x2, y2, 1);
                addedge(y2, x2, 1);
            }
            else {
                addedge(x1, y1, 1);
                addedge(y1, x1, 1);
                addedge(x2, y2, 0);
                addedge(y2, x2, 0);
            }
        }
    }
    int res = bfs();
    if (res == -1) {
        cout << "NO SOLUTION" << endl;
    }
    else {
        cout << res << endl;
    }
    return 0;
}