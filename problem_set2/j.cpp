#include<iostream>
#include<queue>
#include<map>
using namespace std;

const int N = 2e5 + 1;

struct  node {
    int x;
    int y;

    node() {}

    node(int a, int b) :x(a), y(b) {}

    bool operator < (const node& T)const {
        if (x != T.x) {
            return x < T.x;
        }
        else {
            return y < T.y;
        }
    }
    node operator + (const node& T)const {
        node tmp;
        tmp.x = x + T.x;
        tmp.y = y + T.y;
        return tmp;
    }
};
node d[] = { node(-1,0),node(1,0),node(0,1),node(0,-1) };
node a[N];
map<node, int> mp;
map<node, int>vis;
map<node, node>ans;
map<node, node>root;
queue<node>q;

void bfs() {
    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        for (int i = 0;i < 4;i++) {
            node to = cur + d[i];
            if (mp.find(to) != mp.end() && vis.find(to) == vis.end()) {
                vis[to] = 1;
                root[to] = root[cur];
                ans[to] = root[to];
                q.push(to);
            }
        }

    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int x, y;
        cin >> x >> y;
        a[i] = node(x, y);
        mp[node(x, y)] = 1;
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j < 4;j++) {
            node to = d[j] + a[i];
            if (mp.find(to) == mp.end()) {
                q.push(to);
                root[to] = to;
            }
        }
    }
    bfs();
    for (int i = 1;i <= n;i++) {
        cout << ans[a[i]].x << " " << ans[a[i]].y << endl;
    }
    return 0;
}