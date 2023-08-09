#include<iostream>
#include<queue>
#include<map>
using namespace std;
const int N = 1e5 + 1;
struct Edge {
    int to, next;
}edge[N << 1];
int belong[N], vis[N];
int head[N], num;
int ans1, ans2;
int st1, st2;
bool flag;
bool win;
int topoint1, topoint2;
struct node {
    int first;
    int second;
    node() {}
    node(int x, int y) :first(x), second(y) {}
};
queue < node>q1;
queue < node>q2;

void addedge(int x, int y) {
    edge[num].to = y;
    edge[num].next = head[x];
    head[x] = num++;
}

void solve1() {
    belong[st1] = 1;
    belong[st2] = 2;
    q1.push(node(st1, 0));
    q2.push(node(st2, 0));
    while (!q1.empty() || !q2.empty()) {
        if (!q1.empty()) {
            int cur = q1.front().first;
            int curdis = q1.front().second;
            ans1 = max(ans1, curdis);
            q1.pop();
            for (int p = head[cur];~p;p = edge[p].next) {
                int v = edge[p].to;
                if (cur == st1) {
                    if (belong[v] == 0 && v != topoint1) {
                        belong[v] = 1;
                        q1.push(node(v, curdis + 1));
                    }
                }
                else {
                    if (belong[v] == 0) {
                        belong[v] = 1;
                        q1.push(node(v, curdis + 1));
                    }
                }
            }
        }
        if (!q2.empty()) {
            int cur = q2.front().first;
            int curdis = q2.front().second;
            ans2 = max(ans2, curdis);
            q2.pop();
            for (int p = head[cur];~p;p = edge[p].next) {
                int v = edge[p].to;
                if (belong[v] == 0) {
                    belong[v] = 2;
                    q2.push(node(v, curdis + 1));
                }

            }
        }
    }
}


void solve3() {
    belong[st1] = 1;
    belong[st2] = 2;
    q1.push(node(st1, 0));
    q2.push(node(st2, 0));
    while (!q1.empty() || !q2.empty()) {
        if (!q1.empty()) {
            int cur = q1.front().first;
            int curdis = q1.front().second;
            ans1 = max(ans1, curdis);
            q1.pop();
            for (int p = head[cur];~p;p = edge[p].next) {
                int v = edge[p].to;
                if (cur == st1) {
                    if (belong[v] == 0 && v == topoint1) {
                        belong[v] = 1;
                        q1.push(node(v, curdis + 1));
                    }
                }
                else {
                    if (belong[v] == 0) {
                        belong[v] = 1;
                        q1.push(node(v, curdis + 1));
                    }
                }
            }

        }
        if (!q2.empty()) {
            int cur = q2.front().first;
            int curdis = q2.front().second;
            ans2 = max(ans2, curdis);
            q2.pop();
            for (int p = head[cur];~p;p = edge[p].next) {
                int v = edge[p].to;
                if (cur == st2) {
                    if (belong[v] == 0 && v == topoint2) {
                        belong[v] = 2;
                        q2.push(node(v, curdis + 1));
                    }
                }
                else {
                    if (belong[v] == 0) {
                        belong[v] = 2;
                        q2.push(node(v, curdis + 1));
                    }
                }
            }
        }
    }
}

void solve4() {
    belong[st1] = 1;
    belong[st2] = 2;
    q1.push(node(st1, 0));
    q2.push(node(st2, 0));
    while (!q1.empty() || !q2.empty()) {
        if (!q1.empty()) {
            int cur = q1.front().first;
            int curdis = q1.front().second;
            ans1 = max(ans1, curdis);
            q1.pop();
            if (cur != st1)
                for (int p = head[cur];~p;p = edge[p].next) {
                    int v = edge[p].to;
                    if (cur == st1) {
                        if (belong[v] == 0 && v == topoint1) {
                            belong[v] = 1;
                            q1.push(node(v, curdis + 1));
                        }
                    }
                    else {
                        if (belong[v] == 0) {
                            belong[v] = 1;
                            q1.push(node(v, curdis + 1));
                        }
                    }
                }
        }
        if (!q2.empty()) {
            int cur = q2.front().first;
            int curdis = q2.front().second;
            ans2 = max(ans2, curdis);
            q2.pop();
            for (int p = head[cur];~p;p = edge[p].next) {
                int v = edge[p].to;
                if (cur == st2) {
                    if (belong[v] == 0 && v == topoint2) {
                        belong[v] = 2;
                        q2.push(node(v, curdis + 1));
                    }
                }
                else {
                    if (belong[v] == 0) {
                        belong[v] = 2;
                        q2.push(node(v, curdis + 1));
                    }
                }
            }
        }
    }
}

void dfs1(int x) {
    vis[x] = 1;
    if (x == st2) {
        flag = 1;
        return;
    }
    for (int p = head[x];~p;p = edge[p].next) {
        int v = edge[p].to;
        if (!vis[v]) {
            dfs1(v);
        }
        if (flag == 1) {
            if (x == st1) {
                topoint1 = v;
            }
            return;
        }
    }
}

void dfs2(int x) {
    vis[x] = 1;
    if (x == st1) {
        flag = 1;
        return;
    }
    for (int p = head[x];~p;p = edge[p].next) {
        int v = edge[p].to;
        if (!vis[v]) {
            dfs2(v);
        }
        if (flag == 1) {
            if (x == st2) {
                topoint2 = v;
            }
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        win = 0;
        flag = 0;
        num = 0;
        ans1 = ans2 = 0;
        int n;
        cin >> n;
        cin >> st1 >> st2;
        for (int i = 0;i <= n;i++) {
            head[i] = -1;
            belong[i] = 0;
        }
        for (int i = 1;i < n;i++) {
            int x, y;
            cin >> x >> y;
            addedge(x, y);
            addedge(y, x);
        }
        dfs1(st1);
        dfs2(st2);
        solve1();
        if (ans1 > ans2) {
            win = 1;
        }
        for (int i = 0;i <= n;i++) {
            belong[i] = 0;
        }
        ans1 = ans2 = 0;
        solve3();   
        if (ans1 > ans2) {
            win = 1;
        }
        for (int i = 0;i <= n;i++) {
            belong[i] = 0;
        }
        ans1 = ans2 = 0;
        solve4();

        if (ans1 > ans2) {
            win = 1;
        }
        if (win) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }

}