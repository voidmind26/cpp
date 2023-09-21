#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int N = 103;
int a[N];
int main() {
    int n, m;
    string s;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    
    sort(a + 1, a + 1 + n);

    for (int i = n;i >= 1;i--) {
        if (m % a[i] == 0) {
            cout << m / a[i] << endl;
            return 0;
        }

    }
    return 0;
}
