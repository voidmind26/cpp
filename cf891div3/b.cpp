#include<iostream>
#include<string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        int l = a.length();
        int pos = -1;
        for (int i = 0;i < l;i++) {
            if (a[i] >= '5') {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            cout << a << endl;
            continue;
        }
        else if (pos == 0) {
            cout << 1;
            for (int i = 0;i < l;i++) {
                cout << 0;
            }
            cout << endl;
        }
        else {
            bool out = 0;
            for (int i = pos;i < l;i++) {
                a[i] = '0';
            }
            a[pos - 1]++;
            for (int i = pos - 1;i >= 0;i--) {
                if (i == 0 && a[i] >= '5') {
                    cout << 1;
                    for (int i = 0;i < l;i++) {
                        cout << 0;
                    }
                    cout << endl;
                    out = 1;
                    break;
                }
                if (a[i] >= '5') {
                    a[i] = '0';
                    a[i - 1]++;
                }
                else {
                    break;
                }
            }
            if (!out)
                cout << a << endl;
        }
    }
}