#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        if (a == "abc") {
            cout << "YES" << endl;
        }
        else if (a == "acb") {
            cout << "YES" << endl;
        }
        else if (a == "bac") {
            cout << "YES" << endl;
        }
        else if (a == "bca") {
            cout << "NO" << endl;
        }
        else if (a == "cab") {
            cout << "NO" << endl;
        }
        else if (a == "cba") {
            cout << "YES" << endl;
        }
    }

    return 0;
}