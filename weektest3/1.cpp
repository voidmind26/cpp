#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main() {
    char a[1200];
    cin >> a;
    int l = strlen(a);
    int pos = l - 1;
    for (int i = l - 1;i >= 1;i--) {
        if (a[i] > a[i - 1]) {
            pos = i;
            break;
        }
    }
    pos--;
    int pos_;
    char tmp = '9' + 1;
    for (int i = l - 1;i > pos;i--) {
        if (a[i] > a[pos]) {
            if (a[i] < tmp) {
                pos_ = i;
                tmp = a[i];
            }
        }
    }
    tmp = a[pos];
    a[pos] = a[pos_];
    a[pos_] = tmp;
    sort(a + pos + 1, a + l);
    cout << a << endl;
    return 0;
}
