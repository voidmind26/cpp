#include<iostream>
#include<cstring>
using namespace std;

char n1[10];
char n2[10];

bool check(int num1, int num2) {
    char tmp1[100];
    for (int i = 0;i < 10;i++) {
        tmp1[i] = '0';
    }
    tmp1[10] = '\0';
    int i = 0;
    while (num1 != 0) {
        tmp1[i++] = num1 % 10 + '0';
        num1 /= 10;
    }
    tmp1[5] = '\0';
    for (i = 0;i < 5;i++) {
        n1[i] = tmp1[5 - 1 - i];
    }
    n1[5] = '\0';
    char tmp2[100];
    for (int i = 0;i < 10;i++) {
        tmp2[i] = '0';
    }
    tmp2[10] = '\0';
    i = 0;
    while (num2 != 0) {
        tmp2[i++] = num2 % 10 + '0';
        num2 /= 10;
    }
    tmp2[5] = '\0';
    for (i = 0;i < 5;i++) {
        n2[i] = tmp2[5 - 1 - i];
    }
    n2[5] = '\0';
    strcpy(tmp1, n1);
    strcat(tmp1, n2);
    int l = strlen(tmp1);
    for (int j = 0;j < l;j++) {
        for (int k = j + 1;k < l;k++) {
            if (tmp1[k] == tmp1[j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n;
    int a = 0;
    while (cin >> n) {
        bool f = 1;
        cout << "Case " << ++a << ":" << endl;
        for (int i = 98765 / n;i >= 1234;i--) {
            if (check(i, i * n)) {
                f = 0;
                cout << "    " << n2 << "/" << n1 << "=" << n << endl;
            }
        }
        if (f) {
            cout << "    No such numbers" << endl;
        }
    }

    return 0;
}