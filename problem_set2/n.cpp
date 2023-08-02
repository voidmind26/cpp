#include<iostream>

using namespace std;

const int N = 1e4 + 1;

int fa[N];

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
    for (int i = 1;i <= n;i++) {
        fa[i] = i;
    }
    for (int i = 1;i <= m;i++) {
        int f, x, y;
        cin >> f >> x >> y;
        int fx = findfa(x);
        int fy = findfa(y);
        if (f == 1) {
            fa[fy] = fx;
        }
        else {
            if (fx == fy) {
                cout << "Y" << endl;
            }
            else {
                cout << "N" << endl;
            }
        }
    }

    return 0;
}