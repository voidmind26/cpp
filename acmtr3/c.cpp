#include<iostream>
#include<queue>
#include<string>
#define int long long
using namespace std;
const int N = 10004;
struct node {
    int pos;
    int id;

    node() {}
    node(int a, int b):pos(a), id(b) {}
};
int ans[N];
queue<node> lf;
queue<node> rt;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c;
    cin >> c;
    while (c--) {
        int n, m, t;
        cin >> n >> t >> m;
        for (int i = 1;i <= n;i++) {
            ans[i] = 0;
        }
        string a;
        for (int i = 1;i <= m;i++) {
            int x;
            cin >> x;
            cin >> a;
            if (a[0] == 'l') {
                lf.push(node(x, i));
            }
            else {
                rt.push(node(x, i));
            }
        }
        int pos = 0; //0 left  1 right
        int cur = 0;
        while (1) {
            int on = 0;
            if (pos == 0) {
                if (lf.empty()) {
                    cur = rt.front().pos + t;
                    pos = 1;
                    continue;
                }
                if (lf.front().pos > cur) {
                    if (rt.front().pos < lf.front().pos) {
                        cur = rt.front().pos + t;
                        pos = 1;
                        continue;
                    }
                    else {
                        cur = lf.front().pos;
                    }
                }
                while (lf.front().pos <= cur && !lf.empty()) {
                    ans[lf.front().id] = cur + t;
                    lf.pop();
                    on++;
                    if (on == n) {
                        break;
                    }
                }
                cur += t;
                // for (int i = 0;i < on;i++) {
                //     cout << cur << endl;
                // }
                pos = 1;
            }
            else {
                if (rt.empty()) {
                    cur = lf.front().pos + t;
                    pos = 0;
                    continue;
                }
                if (rt.front().pos > cur) {
                    if (rt.front().pos > lf.front().pos) {
                        cur = lf.front().pos + t;
                        pos = 0;
                        continue;
                    }
                    else {
                        cur = rt.front().pos;
                    }
                }
                while (rt.front().pos <= cur && !rt.empty()) {
                    ans[rt.front().id] = cur + t;
                    rt.pop();
                    on++;
                    if (on == n) {
                        break;
                    }
                }
                cur += t;
                // for (int i = 0;i < on;i++) {
                //     cout << cur << endl;
                // }
                pos = 0;
            }
            if (lf.empty() && rt.empty())
                break;
        }
        for (int i = 1;i <= m;i++) {
            cout << ans[i] << endl;
        }
        cout << endl;
    }

    return 0;
}

/*

1
1 10000 10
0 left
0 right
0 left
0 right
0 left
0 right
0 left
0 right
0 left
99999 right

1
2 10 3
10 right
25 left
40 left

*/

