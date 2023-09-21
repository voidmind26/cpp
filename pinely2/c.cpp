#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int N = 1e5 + 1;
priority_queue<int, vector<int>, greater<int>>q;
bool hv[N];
int a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        while (!q.empty()) {
            q.pop();
        }
        int n, k;
        cin >> n >> k;
        for (int i = 0;i <= n;i++) {
            hv[i] = 0;
        }
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            if (a[i] <= n) {
                hv[a[i]] = 1;
            }
        }
        for (int i = 0;i <= n;i++) {
            if (hv[i] == 0) {
                q.push(i);
            }
        }
        for (int i = 1;i <= n;i++) {
            int t = q.top();
            q.pop();
            if (a[i] <= n)
                q.push(a[i]);
            a[i] = t;
        }
        a[0] = q.top();
        q.pop();
        k--;
        for (int i = 1;i <= n;i++) {
            cout << a[((i - k) % (n + 1) + (n + 1)) % (n + 1)] << " ";
        }
        cout << endl;
    }
    return 0;
}