#include<iostream>
using namespace std;
int main() {
    int a;
    cin >> a;
    if (a % 7 == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    while (a > 0) {
        if (a % 10 == 7) {
            cout << "Yes" << endl;
            return 0;
        }
        a /= 10;
    }
    cout << "No" << endl;
    return 0;

}