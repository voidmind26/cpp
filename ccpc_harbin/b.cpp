#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin >> t;
    while (t--) {
        ll p, q;
        cin >> p >> q;
        ll g = __gcd(p, q);
        ll gp = p / g, gq = q / g;
        vector<ll> sp;
        map<ll, ll> sq;
        ll tmp = p;
        while (tmp) {
            sp.push_back(tmp % 10);
            tmp /= 10;
        }
        tmp = q;
        while (tmp) {
            sq[tmp % 10]++;
            tmp /= 10;
        }
        ll ans = p;
        for (ll i = 1, len = sp.size();i < (1ll << len);i++) {
            bool flag = true;
            map<ll, ll> shan;
            shan = sq;
            ll nowp = 0, base = 1;
            for (int j = 0;j < len;j++) {
                if ((1 << j) & i) {
                    nowp += base * sp[j];
                    base *= 10;
                }
                else {
                    if (!shan.count(sp[j])) {
                        flag = false;
                        break;
                    }
                    else {
                        shan[sp[j]]--;
                        if (!shan[sp[j]]) {
                            shan.erase(sp[j]);
                        }
                    }
                }
            }
            if ((nowp * gq) % gp == 0 && flag) {
                ll nowq = nowp * gq / gp;
                while (nowq && flag) {
                    if (!shan.count(nowq % 10)) {
                        flag = false;
                    }
                    else {
                        shan[nowq % 10]--;
                        if (!shan[nowq % 10]) {
                            shan.erase(nowq % 10);
                        }
                        nowq /= 10;
                    }
                }
                if (shan.size() != 0) {
                    flag = false;
                }
                if (flag) {
                    ans = min(ans, nowp);
                }
            }
        }
        cout << ans << " " << ans * gq / gp << "\n";
    }
}