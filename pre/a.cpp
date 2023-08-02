#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

struct hero {
    int strong;
    int len;
    bool operator <  (const hero& T)const {
        if (strong == T.strong) {
            return len > T.len;
        }
        else {
            return strong > T.strong;
        }
    }

    hero() {}

    hero(int a, int b) :strong(a), len(b) {}
};

struct mos {
    int index;
    int strong;
};

const int N = 2e5 + 1;
mos mo[N];
hero hu[N];
int least[N];
int days[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> mo[i].strong;
            mo[i].index = i;
        }
        int m;
        cin >> m;
        for (int i = 1;i <= m;i++) {
            cin >> hu[i].strong >> hu[i].len;
        }

        sort(hu + 1, hu + 1 + m);
        bool imp = 0;

        for (int i = 1;i <= n;i++) {
            least[i] = upper_bound(hu + 1, hu + 1 + m, hero(mo[i].strong, 1)) - hu - 1;
            if (least[i] == 0) {
                imp = 1;
            }
        }
        if (imp) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1;i <= m;i++) {
            days[i] = max(days[i - 1], hu[i].len);
        }

        int ans = 1;
        int curmax = m;
        int st = 0;
        for (int i = 1;i <= n;i++) {
            if (i == 1) {
                curmax = least[1];
                st = 1;
                continue;
            }
            curmax = min(curmax, least[i]);
            if (days[curmax] < i - st + 1) {
                ans++;
                curmax = least[i];
                st = i;
                continue;
            }
        }
        cout << endl;
        cout << ans << endl;
    }

    return 0;
}