#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 20;
char a[N];
char b[N];
char ans[N];
bool flag[N];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    cin >> a >> b;
    int la = strlen(a);
    int lb = strlen(b);
    sort(a, a + la, cmp);
    if (lb > la) {
        for (int i = la -
            1; i >= 0; i--) {
            cout << a[i];
        }
        cout << endl;
        return 0;
    }
    int f = 0;
    for (int i = 0;i < lb;i++) {
        for (int j = i;j < la;j++) {
            if (b[i] == a[j]) {
                swap(a[i], a[j]);
                break;
            }
            if (b[i] > a[j]) {
                swap(a[i], a[j]);
                sort(a + j, a + la, cmp);
                cout << a << endl;
                return 0;

            }
        }
    }
    cout << a << endl;
    return 0;
}