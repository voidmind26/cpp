#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;



int main() {
    long double a[101];
    a[1] = 1.0;
    a[2] = 1.0;
    for (int i = 3;i <= 100;i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    cout << a[100] << endl;
    return 0;
}