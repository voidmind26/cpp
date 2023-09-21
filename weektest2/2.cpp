#include<iostream>
#include<cmath>
#include<cstdio>
#define dl double
using namespace std;
int nm[1000005][2];
double ab[1000005];
int gcd(int a, int b) {
    int r;
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    int n1;
    dl d;
    cin >> n1 >> d;
    int n = n1;
    bool f = 0;
    if (d == int(d)) {
        cout << d << " " << "0.0000000000" << endl;
        return 0;
    }
    dl num = int(d);
    if (n1 == 1) {
        if (d - num > 0.5) {
            printf("%d %.10lf", int(num) + 1, num + 1 - d);
        }
        else if (d - num < 0.5) {
            printf("%d %.10lf", int(num), d - num);
        }
        else {
            cout << "More than one!" << endl;
        }
        return 0;
    }
    int i = 0;
    for (dl s = n1;s >= 2;s--) {
        dl m = int(d * s);
        if (abs(d - m / s) > abs((m + 1) / s - d)) {
            nm[++i][0] = m + 1;
            nm[i][1] = s;
            ab[i] = abs((m + 1) / s - d);
        }
        else if (abs(d - m / s) < abs((m + 1) / s - d)) {
            nm[++i][0] = m;
            nm[i][1] = s;
            ab[i] = abs(d - m / s);
        }
        else {
            nm[++i][0] = -1;
            nm[i][1] = s;
            ab[i] = abs(d - m / s);
        }
    }
    int ans = 0;
    dl flag = 1;
    for (int j = 1;j <= i;j++) {
        if (flag > ab[j]) {
            flag = ab[j];
            ans = j;
        }
    }
    if (nm[ans][0] == -1) {
        cout << "More than one!" << endl;
    }
    else {
        int g = gcd(int(nm[ans][0]), int(nm[ans][1]));
        printf("%d/%d %.10lf\n", int(nm[ans][0]) / g, int(nm[ans][1]) / g, ab[ans]);
    }
    return 0;
}