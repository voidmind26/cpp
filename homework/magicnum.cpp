#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

using namespace std;

int main() {
    int x, n;
    int i = 0;
    while (cin >> x >> n) {
        bool f = 0;
        i++;
        printf("Case %d:\n", i);
        for (int a = 1;a <= n;a++) {
            for (int b = a;b <= n;b++) {
                for (int c = b;c <= n;c++) {
                    for (int d = c;d <= n;d++) {
                        if (pow(a, x) + pow(b, x) + pow(c, x) == pow(d, x)) {
                            printf("%d^%d+%d^%d+%d^%d=%d^%d\n", a, x, b, x, c, x, d, x);
                            f = 1;
                        }
                    }
                }
            }
        }
        if(f==0){
            printf("No such numbers.\n");
        }
    }

    return 0;
}