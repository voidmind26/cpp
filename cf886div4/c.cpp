#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<char>ans;

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        ans.clear();
        for (int i = 1;i <= 8;i++) {
            for (int j = 1;j <= 8;j++) {
                char tmp = getchar();
                if (tmp != '.') {
                    ans.push_back(tmp);
                }
            }
            getchar();
        }
        for (auto i : ans) {
            cout << i;
        }
        cout << "\n";
    }
    return 0;
}