#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
double a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    double sum = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    sum = sum / (n + 1) * 1.0;
    for (int i = 1;i <= n;i++) {
        a[i] = sum;
    }
    a[1] += sum;
    for (int j = 1;j <= n;j++) {
        cout << fixed << setprecision(8) << a[j] << " ";
    }
    cout << "\n";
    return 0;
}