#include<iostream>
#include<cstring>
using namespace std;

int var[10];

int pow(int i) {
    if (i == -1) {
        i = 2;
    }
    int res = 1;
    for (int j = 1;j <= i;j++) {
        res *= 3;
    }
    return res;
}

int main() {
    char n[11];
    cin >> n;

    int l = strlen(n);
    int flag = 1;
    int j = 0;
    for (int i = l - 1;i >= 0;i--) {
        if (flag % 3 == 1 && flag != 1)
            var[++j] += (n[i] - '0') * pow(flag % 3 - 1);
        else {
            var[j] += (n[i] - '0') * pow(flag % 3 - 1);
        }
        flag++;
    }
    char ans[10];
    flag = 0;
    for (int i = 0;i <= j;i++) {
        if (var[i] < 10) {
            ans[flag++] = var[i] + '0';
        }
        else {
            ans[flag++] = var[i] - 10 + 'A';
        }
    }
    ans[flag] = '\0';
    l = strlen(ans);
    for (int i = l - 1;i >= 0;i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}