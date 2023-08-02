#include<iostream>
#define int long long
using namespace std;
const int N = 3e6 + 1;
int p;
int n;
int inv[N];
signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> p;
    inv[1] = 1;
    for (int i = 2;i <= n;i++) {
        inv[i] = (p - p / i) * inv[p % i] % p;
    }
    for (int i = 1;i <= n;i++) {
        cout << inv[i] << "\n";
    }
    return 0;
}