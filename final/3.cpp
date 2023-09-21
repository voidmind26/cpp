#include<iostream>
#include<algorithm>

using namespace std;

const int M = 1e9 + 7;

long long f[1000005];

int main() {
    int n;
    cin >> n;
    f[0] = 4;
    f[1] = 1;
    f[2] = 2;
    f[3] = 2;
    for (int i = 5;i <= n+1;i++) {
        switch (i % 4) {
        case 1:
            f[i % 4] = f[0] % M;
            break;
        case 2:
            f[i % 4] = (f[1] + f[1] + f[3]) % M;
            break;
        case 3:
            f[i % 4] = f[2] % M;
            break;
        case 0:
            f[i % 4] = (f[3] + f[2] + f[0]) % M;
            break;
        }
        // cout << f[i % 4] << endl;
    }
    cout << f[(n + 1) % 4] << endl;
    return 0;
}