#include<iostream>

using namespace std;
const int N = 1e6 + 5;
int a[N];
int sum[N];
int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        sum[i]--;
        sum[max(0, i - a[i])]++;
        if (i != n) {
            sum[i + 1]++;
            sum[min(n+1, i + 1 + a[i])]--;
        }

    }
    for (int i = 1;i <= n;i++) {
        sum[i] += sum[i - 1];
    }
    for (int i = 1;i <= n;i++) {
        cout << sum[i] << " ";
    }
    cout << endl;
    int num = 0;
    for (int i = 1;i <= n;i++) {
        if (sum[i] > 0) {
            num++;
        }
    }
    cout << num << endl;
    return 0;
}