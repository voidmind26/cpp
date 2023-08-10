#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
struct node {
    int index, val, cost;
    node() {}
    node(int x, int y, int i) :val(x), cost(y), index(i) {}
};
const int N = 1e5 + 1;
vector<node> c1, v1; //coin
vector<node> c2, v2; //diamond
bool vis1[N];
bool vis2[N];
int n, c, d;

bool cmpv(node x, node y) {
    return x.val < y.val;
}

bool cmpc(node x, node y) {
    return x.cost < y.cost;
}

bool check1(int x) {
    for (int i = 1;i <= n;i++) {
        vis1[i] = 0;
    }
    int tc = 0;
    int l = 0;
    int r = v1.size() - 1;
    bool get = 0;
    while (l < r) {
        vis1[v1[r].index] = 1;
        tc = v1[r].cost;
        while (v1[l].val + v1[r].val < x && l < v1.size()) {
            vis1[v1[l].index] = 1;
            l++;
        }
        if (l >= r) {
            break;
        }
        for (auto i : c1) {
            if (!vis1[i.index] && i.cost + tc <= c) {
                get = 1;
                break;
            }
        }
        if (get) {
            break;
        }
        r--;
    }
    return get;
}

int solve1(int l, int r) {
    if (l >= r) {
        return l;
    }
    int mid = (l + r + 1) / 2;
    if (check1(mid)) {
        return solve1(mid, r);
    }
    else {
        return solve1(l, mid - 1);
    }
}

bool check2(int x) {
    for (int i = 1;i <= n;i++) {
        vis2[i] = 0;
    }
    int tc = 0;
    int l = 0;
    int r = v2.size() - 1;
    bool get = 0;
    while (l < r) {
        vis2[v2[r].index] = 1;
        tc = v2[r].cost;
        while (v2[l].val + v2[r].val < x && l < v2.size()) {
            vis2[v2[l].index] = 1;
            l++;
        }
        if (l >= r) {
            break;
        }
        for (auto i : c1) {
            if (!vis2[i.index] && i.cost + tc <= c) {
                get = 1;
                break;
            }
        }
        if (get) {
            break;
        }
        r--;
    }
    return get;
}

int solve2(int l, int r) {
    if (l >= r) {
        return l;
    }
    int mid = (l + r + 1) / 2;
    if (check2(mid)) {
        return solve2(mid, r);
    }
    else {
        return solve2(l, mid - 1);
    }
}

signed main() {
    cin >> n >> c >> d;
    for (int i = 1;i <= n;i++) {
        int v, r;
        char type;
        cin >> v >> r >> type;
        if (type == 'C') {
            c1.push_back(node(v, r, i));
            v1.push_back(node(v, r, i));
        }
        else {
            c2.push_back(node(v, r, i));
            v2.push_back(node(v, r, i));
        }
    }
    sort(c1.begin(), c1.end(), cmpc);
    sort(c2.begin(), c2.end(), cmpc);
    sort(v1.begin(), v1.end(), cmpv);
    sort(v2.begin(), v2.end(), cmpv);
    //1+1
    int ans0 = 0;
    int added = 0;
    for (int i = v2.size() - 1;i >= 0;i--) {
        if (v2[i].cost <= d) {
            ans0 += v2[i].val;
            added++;
            break;
        }
    }
    for (int i = v1.size() - 1;i >= 0;i--) {
        if (v1[i].cost <= c) {
            ans0 += v1[i].val;
            added++;
            break;
        }
    }
    if (added != 2) {
        ans0 = 0;
    }
    //2c
    int ans1 = solve1(0, 2 * N);
    //2d
    int ans2 = solve2(0, 2 * N);
    cout << max(ans0, max(ans1, ans2)) << endl;
    return 0;
}