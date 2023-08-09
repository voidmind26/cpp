#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n <= 3) {
            cout << 1 << endl;
        }
        else if (n == 4 || n == 5) {
            cout << 2 << endl;
        }
        else {
            cout << (int)ceil((double)n / 5.0) << endl;
        }
    }
    return 0;
}