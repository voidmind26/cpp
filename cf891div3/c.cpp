#include<iostream>
#include<map>
using namespace std;

map<int, int>save;
map<int, int>ans;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ans.clear();
        save.clear();
        int n;
        cin >> n;
        int mx = -1;
        for (int i = 1;i <= n * (n - 1) / 2;i++) {
            int tmp;
            cin >> tmp;
            save[tmp]++;
        }
        int tol = 0;
        for (auto i : save) {
            for (int j = 1;j <= n;j++) {
                if (j * (j - 1) / 2 + j * (n - tol - j) == i.second) {
                    ans[i.first] = j;
                    tol += j;
                    break;
                }
            }
        }
        ans[1000000000] += n - tol;
        for (auto i : ans) {
            for (int j = 1;j <= i.second;j++) {
                cout << i.first << " ";
            }
        }
        cout << endl;
    }
    return 0;
}