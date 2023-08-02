#include<iostream>
using namespace std;

int cnt = 1;
int maxcnt = -1;
int a[200005];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i < n;i++) {
        if (2 * a[i] >= a[i + 1]) cnt++;
        else {
            maxcnt = max(maxcnt, cnt);
            cnt = 1;
        }
    }
    maxcnt = max(maxcnt, cnt);
    cout << maxcnt << endl;
}