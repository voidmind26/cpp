#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int num1 = a;
        int num2 = b;
        if (c % 2 == 0) {
            num1 += c / 2;
            num2 += c / 2;
        }
        else {
            num1 += c / 2 + 1;
            num2 += c / 2;
        }
        if (num1 > num2) {
            cout << "First" << "\n";
        }
        else {
            cout << "Second" << "\n";
        }
    }


    return 0;
}