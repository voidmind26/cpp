#include<bits/stdc++.h>
using namespace std;

const int N = 1.1e7 + 1;
int p[N << 1], n;
char a[N], s[N << 1];

void change() {
    n = strlen(a);
    s[0] = '$';
    s[1] = '#';
    int k = 2;
    for (int i = 0;i < n;i++) {
        s[k++] = a[i];
        s[k++] = '#';
    }
    s[k++] = '&';
    n = k;
}

void solve() {
    int r = 0, c;
    for (int i = 1;i < n;i++) {
        if (i < r) {
            p[i] = min(p[2 * c - i], p[c] + c - i);
        }
        else {
            p[i] = 1;
        }
        while (s[i + p[i]] == s[i - p[i]]) {
            p[i]++;
        }
        if (p[i] + i > r) {
            r = p[i] + i;
            c = i;
        }
    }
}

int main() {
    cin >> a;
    change();
    solve();
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        ans = max(ans, p[i] - 1);
    }
    cout << ans << "\n";
    return 0;
}