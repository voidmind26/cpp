#include<bits/stdc++.h>

using namespace std;

int main() {
    int s;
    while (cin >> s) {
        getchar();
        char type = getchar();
        switch (type) {
        case 'K':
            if (s == 1)
                cout << 1 << endl;
            else
                cout << 4 << endl;
            break;

        case 'N':
            if (s <= 2) {
                cout << 1 << endl;
            }
            else {
                cout << 2 << endl;
            }
            break;

        case 'B':
            cout << s << endl;
            break;

        case 'R':
            cout << s << endl;
            break;
        }
    }

    return 0;
}