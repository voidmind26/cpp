#include<iostream>
#include<string>
using namespace std;
const int N = 1e5 + 1;
int nextl[N];
int nextr[N];
int abs(int x) {
    return x >= 0 ? x : -x;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a;
        cin >> a;
        int l = 0;
        int r = n - 1;
        int last = -1;
        for (int i = 0;i < n;i++) {
            if (a[i] == '0') {
                if (last == -1) {
                    last = i;
                    continue;
                }
            }
            else {
                nextl[last] = abs(i - last - 1);
                last = i;
            }
        }
        nextl[last] = -1;
        last = -1;
        for (int i = n - 1;i >= 0;i--) {
            if (a[i] == '0') {
                if (last == -1) {
                    last = i;
                    continue;
                }
            }
            else {
                nextr[last] = abs(i - last - 1);
                last = i;
            }
        }
        nextr[last] = -1;
        while (l >= r) {
            if (a[l] == a[r] && a[l] == '1') {
                cout << 1 << endl;
                break;
            }
            if (a[l] == a[r] && a[l] == '0') {
                if (nextl[l] >= nextr[r]) {
                    l++;
                }
            }
        }
    }

    return 0;
}