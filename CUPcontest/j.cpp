#include<iostream>

using namespace std;

inline int gcd(int a, int b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a, b;
        a = n - 1;
        b = n * (n - 2);
        a /= gcd(a, b);
        b /= gcd(a, b);
        cout << a << " " << b << endl;
    }

    return 0;
}