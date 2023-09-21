#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (y2 - y1 < x2 - x1 || y2 - y1 < 0) {
            cout << -1 << endl;
        }
        else {
            cout << x1 + (y2 - y1) - x2 + (y2 - y1) << endl;
        }
    }

    return 0;
}