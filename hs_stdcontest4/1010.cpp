#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (m < n) {
            swap(n, m);
        }
        if (n == 1) {
            cout << (m + 1) / 2 << endl;
            continue;
        }
        else if (n % 3 == 0 || m % 3 == 0) {
            cout << 2 << endl;
        }
        else {
            cout << 1 << endl;
        }
    }
    return 0;
}