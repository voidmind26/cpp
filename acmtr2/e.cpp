#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1000005;
struct Edge {
    int from;
    int to;
};
Edge edge[N];

int fa[N];
vector<int>ans;
bool vis[N];
int mrank[N];

struct Edge2 {
    int next, to;
    int id;
}edge2[N];
int head[N];
bool solve = 0;

int findfa(int x) {
    if (fa[x] == x) {
        return x;
    }
    else {
        return fa[x] = findfa(fa[x]);
    }
}

void unite(int x, int y) {
    int fx = findfa(x);
    int fy = findfa(y);

    if (mrank[fx] > mrank[fy]) {
        fa[fy] = fx;
    }
    else {
        fa[fx] = fy;
        if (mrank[fx] == mrank[fy])
            mrank[fy]++;
    }

}

int cnt = 0;
void add(int x, int y, int id) {
    edge2[cnt].to = y;
    edge2[cnt].next = head[x];
    edge2[cnt].id = id;
    head[x] = cnt++;
}

void dfs(int c, int s, int ls) {
    vis[c] = 1;
    for (int p = head[c];~p;p = edge2[p].next) {
        int to = edge2[p].to;
        if (to == s && to != ls) {
            ans.push_back(edge2[p].id);
            solve = 1;
            return;
        }
        if (!vis[to]) {
            ans.push_back(edge2[p].id);
            dfs(to, s, c);
            if (solve) {
                return;
            }
            ans.pop_back();
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cnt=0;
        ans.clear();
        int n, m;
        cin >> n >> m;
        for (int i = 1;i <= n;i++) {
            fa[i] = i;
            vis[i] = 0;
            head[i] = -1;
            mrank[i] = 0;

        }
        for (int i = 1;i <= m;i++) {
            cin >> edge[i].from;
            cin >> edge[i].to;
        }
        int m2;
        int s;
        int cls;
        bool get = 0;
        for (int i = 1;i <= m;i++) {
            int u = edge[i].from;
            int v = edge[i].to;
            if (findfa(u) == findfa(v)) {
                s = edge[i].from;
                cls = findfa(u);
                m2 = i;
                get = 1;
                break;
            }
            else {
                unite(u, v);
            }
        }

        if (!get) {
            cout << -1 << endl;
            continue;
        }
        else {
            for (int i = 1;i <= m2;i++) {
                if (findfa(edge[i].from) == cls && findfa(edge[i].to) == cls) {
                    add(edge[i].from, edge[i].to, i);
                    add(edge[i].to, edge[i].from, i);
                }
            }
            solve = 0;
            dfs(s, s, -1);
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size();i++) {
                cout << ans[i];
                if (i != ans.size() - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }



    return 0;
}


/*
5
8 9
1 2
2 3
3 6
5 6
6 7
7 8
4 7
2 4
4 6
8 9
1 2
2 3
3 6
5 6
6 7
7 8
4 7
2 4
4 6
8 9
1 2
2 3
3 6
5 6
6 7
7 8
4 7
2 4
4 6
8 9
1 2
2 3
3 6
5 6
6 7
7 8
4 7
2 4
4 6
8 9
1 2
2 3
3 6
5 6
6 7
7 8
4 7
2 4
4 6



*/