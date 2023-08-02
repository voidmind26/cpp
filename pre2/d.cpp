#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
const int M = 2e3 + 1;
const int N = 1e6 + 1;

priority_queue<int, vector<int>, greater<int>>pos[M];
int a[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        pos[a[i]].emplace(i);
    }
    int l = 1;
    int r = 1;
    int ans = 0;
    for (int i = 1;i <= m;i++) {
        r = max(r, pos[i].top());
    }
    int ansr, ansl;
    ans = r - l + 1;
    ansr = r;
    ansl = l;
    while (1) {
        if (pos[a[l]].size() == 1) {
            break;
        }
        pos[a[l]].pop();
        r = max(r, pos[a[l]].top());
        l++;
        if (ans > (r - l + 1)) {
            ans = r - l + 1;
            ansl = l;
            ansr = r;
        }
    }
    cout << ansl << " " << ansr << endl;
    return 0;
}