#include<iostream>
#include<algorithm>
using namespace std;

int a[3];

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0;i < 3;i++) {
            cin >> a[i];
        }
        sort(a, a + 3);
        if (a[1] + a[2] >= 10) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}