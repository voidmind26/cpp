#include<iostream>
#include<algorithm>

using namespace std;
char ans[100001];
char sy[] = { '1','2','3','4','5','6','7','8','9' };

int main() {
    int n;
    cin >> n;
    int n9 = n / 9;
    int l = 0;
    int tmp = 0;
    bool flag = 0;
    for (int i = 1;;i++) {
        tmp += i;
        if (tmp >= n9) {
            if (tmp == n9) {
                flag = 1;
            }
            l = i;
            break;
        }
    }
    int t;
    if (flag) {
        t = n % 9;
    }
    else {
        t = n % 9 + (n9 - tmp + l) * 9;
    }
    int num1;
    if (t == 0) {
        t = 9;
    }
    if (t % l == 0) {
        num1 = t / l;
    }
    else {
        num1 = t / l + 1;
    }
    cout << num1 << " " << l << endl;
    return 0;
}