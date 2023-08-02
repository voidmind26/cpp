#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 1e5 + 7;
double a[N];
double b[N];
vector<double>tmp;
int n, k;
const double INF = 1e-9;

bool cmp(double x, double y) {
    return x > y;
}

bool check(double x) {
    tmp.clear();
    for (int i = 1;i <= n;i++) {
        tmp.push_back(a[i] - x * b[i]);
    }
    sort(tmp.begin(), tmp.end(), cmp);
    double res = 0;
    for (int i = 0;i < k;i++) {
        res += tmp[i];
    }
    if (res >= 0) {
        return 1;
    }
    else {
        return 0;
    }
}

double merge(double l, double r) {
    if (r - l <= INF) {
        return l;
    }
    double mid = (l + r) / 2.0;
    if (check(mid)) {
        return merge(mid, r);
    }
    else {
        return merge(l, mid);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> b[i];
    }
    double ans = merge(0, 1);
    cout << ans << "\n";
    return 0;
}