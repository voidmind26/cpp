#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n, pos, l, r;
int main() {
    int ans = 0;
    cin >> n >> pos >> l >> r;
    if (l == 1 && r == n) {
        cout << 0 << endl;
        return 0;
    }
    if (l == 1 && pos == r) {
        cout << 1 << endl;
        return 0;
    }
    if (l == pos && r == n) {
        cout << 1 << endl;
        return 0;
    }
    if (l == 1) {
        if (pos <= r) {
            ans += 1;
            ans += r - pos;
        }
        else {
            ans += 1;
            ans += pos - r;
        }
        cout << ans << endl;
        return 0;
    }
    if (r == n) {
        if (pos >= l) {
            ans += 1;
            ans += pos - l;
        }
        else {
            ans += 1;
            ans += l - pos;
        }
        cout << ans << endl;
        return 0;
    }
    if (pos >= l && pos <= r) {
        ans += min(r - pos, pos - l);
        ans += 2;
        ans += r - l;
        cout << ans << endl;
        return 0;
    }
    if (pos < l) {
        ans = l - pos + 2 + r - l;
        cout << ans << endl;
        return 0;
    }
    if (pos > r) {
        ans = pos - r + 2 + r - l;
        cout << ans << endl;
        return 0;
    }
    return 0;
}