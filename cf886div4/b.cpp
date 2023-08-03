#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a, b;
        int mxb;
        mxb = 0;
        int ans = 0;
        for (int i = 1;i <= n;i++) {
            cin >> a >> b;
            if (a > 10) {
                continue;
            }
            else {
                if (b > mxb) {
                    mxb = b;
                    ans = i;
                }
            }
        }
        cout << ans << endl;    
    }

    return 0;
}