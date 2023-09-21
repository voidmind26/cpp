#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int low, high;
    low = 0;
    high = 0;
    int num = 0;
    for (int i = 1;i <= n;i++) {
        int l, h;
        cin >> l >> h;
        if (l > k) {
            low += l - k;
        }
        else {
            if (h < k)
                high += k - h;
            num += k - l;
        }

    }
    if (max(high, low) <= num)
        cout << max(high, low) << endl;
    else
        cout << -1 << endl;
    return 0;
}