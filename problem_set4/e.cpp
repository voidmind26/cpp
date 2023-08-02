#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;
const int N = 103;
double a[N][N];
const double eps = 1e-7;


int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n + 1;j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1;i <= n;i++) {
        int mx = i;
        for (int j = i;j <= n;j++) {
            if (fabs(a[j][i]) > fabs(a[mx][i])) {
                mx = j;
            }
        }
        for (int j = 1;j <= n+1;j++) {
            swap(a[mx][j], a[i][j]);
        }
        if (fabs(a[i][i]) < eps) {
            cout << "No Solution" << endl;
            return 0;
        }
        for (int j = n + 1;j >= 1;j--) {
            a[i][j] /= a[i][i];
        }
        for (int j = 1;j <= n;j++) {
            double tmp = a[j][i] / a[i][i];
            if (j != i)
                for (int k = 1;k <= n + 1;k++) {
                    a[j][k] -= a[i][k] * tmp;
                }
        }
    }
    for (int i = 1;i <= n;i++) {
        printf("%.2lf\n", a[i][n + 1]);
    }
    return 0;
}