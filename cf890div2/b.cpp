#include<iostream>
using namespace std;
#define int long long
int n;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int tmp;
        int num = 0;
        int num1 = 0;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> tmp;
            if (tmp != 1) {
                num += tmp - 1;
            }
            else {
                num1++;
            }
        }
        if (num >= num1 && n != 1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}