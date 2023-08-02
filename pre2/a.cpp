#include<iostream>
#define int long long

using namespace std;

const int N = 5e5 + 1;

int a[N];
int lef[N];
int rig[N];
int n;
int ans = 0;

void resolve(int l, int r) {
    int mid = (l + r) / 2;
    for (int i = l;i <= mid;i++) {
        lef[i] = a[i];
    }
    for (int i = mid + 1;i <= r;i++) {
        rig[i] = a[i];
    }

    int li = l;
    int ri = mid + 1;

    for (int i = l;i <= r;i++) {
        if (lef[li] <= rig[ri] && li <= mid) {
            a[i] = lef[li];
            li++;
        }
        else if (ri <= r) {
            a[i] = rig[ri];
            ri++;
            ans += mid - li + 1;
        }
        else {
            a[i] = lef[li];
            li++;
        }
    }
    // cout << l << " " << r << " " << ans << endl;

}

void merge(int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) / 2;
    merge(l, mid);
    merge(mid + 1, r);
    resolve(l, r);
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    merge(1, n);
    cout << ans << endl;
    return 0;
}