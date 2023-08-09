#include<iostream>
#include<vector>
using namespace std;

int save[1001];
int n;
int out = 0x7fffffff;
int ans = 0;
void check() {
    ans = 0;
    int num[] = { 0,0,0,0 };
    for (int i = 0;i < n;i++) {
        for (int j = i;j < n;j++) {
            for (int k = 1;k <= 3;k++) {
                num[k] = 0;
            }
            int l = j - i + 1;
            for (int k = i;k <= j;k++) {
                num[save[k]]++;
            }
            int place;
            if (l % 2 == 1) {
                place = (l + 1) / 2;
                int sum = 0;
                for (int k = 1;k <= 3;k++) {
                    sum += num[k];
                    if (sum >= place) {
                        ans = max(ans, num[k]);
                        break;
                    }
                }
            }
            else {
                place = l / 2;
                int sum = 0;
                for (int k = 1;k <= 3;k++) {
                    sum += num[k];
                    if (sum >= place) {
                        ans = max(ans, num[k]);
                        break;
                    }
                }
                place = l / 2 + 1;
                sum = 0;
                for (int k = 1;k <= 3;k++) {
                    sum += num[k];
                    if (sum >= place) {
                        ans = max(ans, num[k]);
                        break;
                    }
                }
            }
        }
    }
    out = min(out, ans);
    if (ans == 3) {
        for (int i = 0;i < n;i++) {
            cout << save[i] << " ";
        }
        cout << endl;
    }

}
void dfs(int d) {
    if (d == n) {
        check();
        return;
    }
    for (int i = 1;i <= 3;i++) {
        save[d] = i;
        dfs(d + 1);
    }
}

int main() {
    // for (int i = 1;i <= 20;i++) {
    out = 0x7fffffff;
    n = 16;
    dfs(0);
    // cout << i << " " << out << endl;
    // }

    return 0;
}