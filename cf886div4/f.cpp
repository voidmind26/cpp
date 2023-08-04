#include<iostream>
#include<map>
using namespace std;
const int N = 2e5 + 1;
map<int, int>save;
int ans[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        save.clear();
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            ans[i] = 0;
            int tmp;
            cin >> tmp;
            if (save.find(tmp) == save.end()) {
                save[tmp] = 1;
            }
            else {
                save[tmp]++;
            }
        }
        for (auto i : save) {
            for (int j = 1;j <= n;j++) {
                if (j * i.first > n) {
                    break;
                }
                ans[j * i.first] += i.second;
            }
        }
        int mx = 0;
        for (int i = 1;i <= n;i++) {
            mx = max(ans[i], mx);
        }
        cout << mx << endl;
    }
    return 0;
}