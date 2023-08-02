#include<iostream>

using namespace std;

const int N = 5e4 + 1;

int fa[N * 3];

int findfa(int x) {
    if (fa[x] == x) {
        return x;
    }
    else {
        return fa[x] = findfa(fa[x]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= 3 * n;i++) {
        fa[i] = i;
    }
    int ans = 0;
    for (int i = 1;i <= m;i++) {
        int f, x, y;
        cin >> f >> x >> y;
        if (x > n || y > n) {
            ans++;
            continue;
        }
        int xs = findfa(x);
        int ys = findfa(y);
        if (f == 1) {
            if (findfa(x + n) == findfa(y) || findfa(x) == findfa(y + n)) {
                ans++;
                continue;
            }
            else {
                fa[findfa(x)] = findfa(y);
                fa[findfa(x + n)] = findfa(y + n);
                fa[findfa(x + n + n)] = findfa(y + n + n);
            }
        }
        else {
            if (findfa(x) == findfa(y) || findfa(x) == findfa(y + n)) {
                ans++;
                continue;
            }
            else {
                fa[findfa(x + n)] = findfa(y);
                fa[findfa(x + n + n)] = findfa(y + n);
                fa[findfa(x)] = findfa(y + n + n);
            }
        }
    }
    cout << ans << endl;
    return 0;
}