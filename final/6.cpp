#include<iostream>
#include<algorithm>
using namespace std;
int a[100001];
int b[100001];
int main() {
    int n;
    cin >> n;

    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> b[i];
    }
    int min = a[1] + b[n];
    for (int i = 1;i <= n;i++) {
        if (min > (a[i] + b[n + 1 - i])) {
            min = a[i] + b[n + 1 - i];
        }
    }
    cout << min << endl;

    return 0;
}