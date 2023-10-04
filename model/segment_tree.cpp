#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7;
int n, p;
int tree[N << 2], lazy[N << 2];
int a[N];

void build(int root, int l, int r) {
    if (l >= r) {
        tree[root] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(root << 1, l, mid);
    build(root << 1 | 1, mid + 1, r);
    tree[root] = tree[root << 1] + tree[root << 1 | 1];
}

void pushdown(int root, int l, int r) {
    int mid = (l + r) / 2;
    tree[root << 1] += (mid - l + 1) * lazy[root];
    tree[root << 1 | 1] += (r - mid) * lazy[root];
    lazy[root << 1 | 1] += lazy[root];
    lazy[root << 1] += lazy[root];
    lazy[root] = 0;
}

int query(int root, int l, int r, int x, int y) {
    if (x >= l && r <= y) {
        return tree[root];
    }
    if (x > r || l > y) {
        return 0;
    }
    int mid = (l + r) / 2;
    if (lazy[root] != 0)
        pushdown(root, l, r);
    return query(root << 1, 1, mid, x, y) + query(root << 1 | 1, mid + 1, r, x, y);
}

void change(int root,int l,int r,int x,int y,int k){
    if()
}

signed main() {
    cin >> n >> p;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1;i <= p;i++) {
        int f;
        cin >> f;
        if (f == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            change(1, 1, n, x, y, k);
        }
        else {
            int x, y;
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << "\n";
        }
    }
    return 0;
}