#include<bits/stdc++.h>

#define endl "\n"

using namespace std;

const int N = 4e4 + 1;
int ans[N];

struct node {
    int num, a, b;
}save[N];

bool cmp1(node a, node b) {
    return a.a > b.a;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> save[i].a;
            save[i].num = i;
        }
        sort(save + 1, save + 1 + n, cmp1);
        for (int i = 1;i <= n;i++) {
            save[i].b = i;
            ans[save[i].num] = save[i].b;
        }
        for (int i = 1;i <= n;i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}