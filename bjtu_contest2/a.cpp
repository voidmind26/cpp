#include<cstdio>
#include<algorithm>
using namespace std;

int n;
double m;
double a, b;
double min1 = 9999999;

int main() {
    scanf("%d%lf", &n, &m);
    for (int i = 1;i <= n;i++) {
        scanf("%lf%lf", &a, &b);
        if (a / b < min1) {
            min1 = a / b;
        }
    }
    printf("%.8lf", min1 * m);
    return 0;
}