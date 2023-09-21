#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>

using namespace std;

const int N = 10004;
stack<int> s;

struct Edge {
    int to;
    int next;
}edge[N];

int head[N];
int n, m;
int num = 0;
bool vis[N];

void add(int x, int y) {
    edge[num].next = head[x];
    edge[num].to = y;
    head[x] = num;
    num++;
}

void dfs(int x) {
    vis[x] = 1;
    cout << x << " ";
    s.push(x);

    while (!s.empty()) {
        int cur = s.top();
        vis[cur] = 1;
        int flag = 0;
        for (int p = head[cur];p != -1;p = edge[p].next) {
            int to = edge[p].to;
            if (!vis[to]) {
                flag = 1;
                cout << to << " ";
                s.push(to);
                break;
            }
        }
        if (!flag) {
            s.pop();
        }
    }

}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0;i < m; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    int s;
    cin >> s;
    dfs(s);
    return 0;
}