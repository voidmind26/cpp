#include<iostream>

using namespace std;
const int N = 5e6 + 1;
int a[N];
int n, k;
int ans;
int sl[N], sr[N];

void merge(int l, int r) {
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    for (int i = l;i <= mid;i++) {
        sl[i] = a[i];
    }
    for (int i = mid + 1;i <= r;i++) {
        sr[i] = a[i];
    }
    int tl = l;
    int tr = mid + 1;
    for (int i = l;i <= r;i++) {
        if (sl[tl] < sr[tr] && tl <= mid) {
            a[i] = sl[tl];
            tl++;
        }
        else if (sl[tl] > sr[tr] && tr <= r) {
            a[i] = sr[tr];
            tr++;
        }
        else if (tl > mid) {
            a[i] = sr[tr];
            tr++;
        }
        else if (tr > r) {
            a[i] = sl[tl];
            tl++;
        }
        if (l == 1 && r == n && i == k + 1) {
            ans = a[i];
        }
    }

}

void solve(int l, int r) {
    if (r <= l) {
        return;
    }
    int mid = (l + r) / 2;
    solve(l, mid);
    solve(mid + 1, r);
    merge(l, r);
}

int main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    solve(1, n);
    cout << ans << endl;
    return 0;
}