#include<iostream>
#include<vector>
#include<set>
#include<cmath>
#define int long long 
#define INF 1e-9
using namespace std;
const int N = 17;

int x[N];
int y[N];
int n;
vector<set<int>>rt;
vector<set<int>>ob;


bool check_ag(int a, int b, int c) {
    int i1 = x[a] - x[b];
    int j1 = y[a] - y[b];
    int i2 = x[c] - x[b];
    int j2 = y[c] - y[b];
    if (i1 == j1 && i1 == 0) {
        return false;
    }
    if (i2 == j2 && i2 == 0) {
        return false;
    }
    if (i1 * i2 + j1 * j2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

double dis(int a, int b) {
    return sqrt(pow(double(x[a] - x[b]), 2) + pow(double(y[a] - y[b]), 2));
}

bool check_dis(int a, int b, int c, int d) {
    if (dis(a, b) - dis(c, d) < INF && dis(a, c) - dis(b, d) < INF && dis(a, d) - dis(c, b) < INF && dis(a, b) != dis(a, c) && dis(a, b) != dis(a, d)) {
        return true;
    }
    else {
        return false;
    }
}

set<int> create4(int a, int b, int c, int d) {
    set<int> t;
    t.insert(a);
    t.insert(b);
    t.insert(c);
    t.insert(d);
    return t;
}

set<int> create3(int a, int b, int c) {
    set<int> t;
    t.insert(a);
    t.insert(b);
    t.insert(c);
    return t;
}

void check_ob(int a, int b, int  c, int  d) {
    if (check_ag(c, d, a) || check_ag(a, d, b) || check_ag(b, d, c)) {
        if (check_dis(a, b, c, d) && check_dis(a, c, b, d) && check_dis(a, d, c, b)) {
            ob.push_back(create4(a, b, c, d));
        }
        else {
            return;
        }
    }
    else {
        return;
    }
}

void check_rt(int a, int b, int  c) {
    if (check_ag(a, b, c) || check_ag(b, c, a) || check_ag(c, a, b)) {
        rt.push_back(create3(a, b, c));
    }
    else {
        return;
    }
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
                for (int l = k + 1; l <= n; l++) {
                    check_ob(i, j, k, l);
                }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++) {
                check_rt(i, j, k);
            }
    int ans = 0;
    for (auto i : rt) {
        for (auto j : ob) {
            set<int>c;
            c.insert(i.begin(), i.end());
            c.insert(j.begin(), j.end());
            if (c.size() == 7) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}