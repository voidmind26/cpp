#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100;
int a[N];
int sum[N];
int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        sort(a + 1, a + 1 + i);
        for (int j = 1;j <= n;j++) {
            cout << a[j] << " ";
            sum[j] += a[j];
        }
        cout << endl;
    }
    for (int i = 1;i <= n;i++) {
        cout << sum[i] << " ";
    }
    cout<<endl;
    return 0;
}