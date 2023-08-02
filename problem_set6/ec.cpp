#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5e6 + 1;

int a[N];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    cout<<a[k+1]<<endl;
    return 0;
}