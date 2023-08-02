#include<iostream>
#include<random>
#include<vector>
#include<ctime>
#define int long long
using namespace std;
const int N = 2e5 + 7;

bool vis[N];
vector<int>ans;
int n;
int a[N], b[N];
int suma, sumb;
signed main() {
    mt19937 rnd(time(0));
    cin >> n;
    for (int i = 1;i <= 2 * n + 1;i++) {
        cin >> a[i] >> b[i];
        suma += a[i];
        sumb += b[i];
    }
    for (int i = 1;i <= 80;i++) {
        for (int i = 1;i <= 2 * n + 1;i++)
            vis[i] = 0;
        ans.clear();
        do {
            int tmp = rnd() % (2 * n + 1) + 1;
            if (!vis[tmp]) {
                vis[tmp] = 1;
                ans.push_back(tmp);
            }
        } while (ans.size() < n + 1);
        int tmpa = 0;
        int tmpb = 0;
        for (auto i : ans) {
            tmpa += a[i];
            tmpb += b[i];
        }
        if (suma - tmpa < tmpa && sumb - tmpb < tmpb) {
            for (auto i : ans) {
                cout << i << "\n";
            }
            break;
        }
    }
    return 0;
}