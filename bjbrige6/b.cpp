#include<iostream>
#include<string>
using namespace std;

const int Max = 4096;

int main() {
    int n;
    cin >> n;
    if (n <= Max) {
        for (int i = 0; i < n; i++) {
            cout << 'a';
        }
        cout << endl;
    }
    else {
        if (n % 2 == 1) {
            for (int i = 0; i < n / 2; i++) {
                cout << 'a';
            }
            cout << 'b';
            cout << endl;
        }
        else if (n % 4 == 0) {
            string a = "aabb";
            for (int i = 0;i < n / 4 + 2;i++) {
                cout << a[i % 4];
            }
            cout << endl;
        }
        else {
            for (int i = 0; i < n / 4 - 1; i++) {
                cout << 'a';
            }
            cout << "bcd" << endl;
        }
    }
    return 0;
}