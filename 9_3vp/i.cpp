#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int ori;
    int a;
    cin >> a;
    ori = a;
    int num = 0;
    int num1 = 0;
    while (a != 0) {
        if (a % 2 == 1) {
            num1++;
        }
        num++;
        a /= 2;
    }
    int aft;
    aft = pow(2, num - 1) + pow(2, num1-1) - 1;
    cout << ori - aft << "\n";
    return 0;
}