#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 20005;
int map[N];


int main() {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x2 = abs(x2 - x1);
    y2 = abs(y2 - y1);
    int size = max(x2, y2);
    map[0] = size * 2;
    int f = -1;
    for (int i = 1;i <= size;i++) {
        map[i] = map[i - 1] + f;
        f = -f;
    }
    cout << map[abs(x2 - y2)] << endl;
    return 0;
}
