#include<iostream>
#include<algorithm>
using namespace std;

const int N = 40000;
int a[N];
int n;

int main() {
    cin >> n;
    for (int i = 1;i <= n - 1; i++)
        cin >> a[i];
    sort(a + 1, a + n);
    for (int i = 1; i <= n - 1; i++) {
        if (a[i] != i) {
            cout << i << endl;
            return 0;
        }
    }
    cout<<n<<endl;
    return 0;
}