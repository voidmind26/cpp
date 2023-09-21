#include<iostream>
#define ll long long
using namespace std;
const int N = 100005;
int n;
int a[N];
int p[N];
int m[N];
int o[N];
int main() {
    cin >> n;

    int t;
    for (int i = 1;i <= n;i++) {
        cin >> t;
        if (t == 0) {
            a[i] = 0;
        }
        if (t > 0) {
            a[i] = 1;
        }
        if (t < 0) {
            a[i] = -1;
        }
    }
    o[0] = 0;
    for (int i = 1;i <= n;i++) {
        o[i] = o[i - 1];
        if (a[i] == 0) {
            o[i] += m[i - 1] + p[i - 1] + 1;
        }
        if (a[i] > 0) {
            p[i] = p[i - 1] + 1;
            m[i] = m[i - 1];
        }
        if (a[i] < 0) {
            p[i] = m[i - 1];
            m[i] = p[i - 1] + 1;
        }
    }
    ll ansp = 0;
    ll ansm = 0;
    ll anso = 0;
    for (int i = 1;i <= n;i++) {
        ansp += p[i];
        ansm += m[i];
        anso += o[i];
    }
    cout << ansm << " " << anso << " " << ansp << endl;
    return 0;
}