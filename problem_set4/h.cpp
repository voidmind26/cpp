#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

inline int gcd(int x, int y) {
    return y ? gcd(y, x%y) : x;
}

int main() {
    int ans;
    int n;
    cin>>n;
    for (int i = 1;i <= n;i++) {
        int t;
        cin >> t;
        if (i == 1) {
            ans = t;
        }
        else {
            if (t < 0)
                t = -t;
            ans = gcd(t, ans);
        }
    }
    cout << ans << endl;
    return 0;
}