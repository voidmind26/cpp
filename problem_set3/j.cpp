#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e4 + 1;
vector<int>w;
vector<int>r;
int dp[1001];

void pre(int tmpr, int tmpw, int tmpnum) {
    int t = 1;
    while (tmpnum != 0) {
        w.push_back(tmpw * t);
        r.push_back(tmpr * t);
        tmpnum -= t;
        t *= 2;
        if (tmpnum < t) {
            w.push_back(tmpw * tmpnum);
            r.push_back(tmpr * tmpnum);
            tmpnum = 0;
            break;
        }
    }
}

int main() {
    int h1, m1, h2, m2;
    char tmp;
    int n, v;
    cin >> h1 >> tmp >> m1 >> h2 >> tmp >> m2 >> n;
    v = h2 * 60 + m2 - h1 * 60 - m1;
    for (int i = 1;i <= n;i++) {
        int tmpr, tmpw, tmpnum;
        cin >> tmpr>>tmpw>>tmpnum;
        if (tmpnum == 0) {
            pre(tmpr, tmpw, 1e3 + 6);
        }
        else {
            pre(tmpr, tmpw, tmpnum);
        }
    }
    for (int i = 0;i < w.size();i++) {
        for (int j = v;j >= r[i];j--) {
            dp[j] = max(dp[j], dp[j - r[i]] + w[i]);
        }
    }
    cout << dp[v] << endl;
    return 0;
}