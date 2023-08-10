#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N = 1e5 + 1;

int tree[N << 2], lazy[N << 2];
int a[N], n, q;

void build(int root, int l, int r) {
    if (l >= r) {
        tree[l] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(root << 1, l, mid);
    build(root << 1 | 1, mid + 1, r);
    tree[root] = tree[root << 1] + tree[root << 1 | 1];
}

signed main() {
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1;i <= q;i++) {

    }
    return 0;
}