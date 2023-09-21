#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<char> ans;
const int N = 20;
int num[N];
char a[N];
char b[N];
char c[N];
int main() {
    cin >> a >> b;
    int la = strlen(a);
    int lb = strlen(b);
    for (int i = 0;i < la;i++) {
        num[a[i] - '0']++;
    }
    if (lb > la) {
        for (int i = 9;i >= 0;i--) {
            while (num[i] != 0) {
                cout << i;
                num[i]--;
            }
        }
        return 0;
    }
    bool flag = 0;
    for (int i = 0;i < lb;i++) {
        if (flag) {
            ans.pop_back();
            b[i]--;
            num[b[i] - '0']--;
            ans.push_back(b[i] - '0');
            for (int i = 9;i >= 0;i--) {
                while (num[i] != 0) {
                    ans.push_back(i);
                }
            }
            break;
        }
        if (num[b[i] - '0'] > 0) {
            c[i] = b[i];
            num[b[i] - '0']--;
            ans.push_back(b[i]);
            continue;
        }
        else {
            for (int j = b[i] - '0' - 1;j >= 0;j--) {
                if (num[j] > 0) {
                    c[i] = j;
                    num[j]--;
                    ans.push_back(j);
                    for (int i = 9;i >= 0;i--) {
                        while (num[i] != 0) {
                            ans.push_back(i);
                        }
                    }
                    break;
                }
            }
        }
        flag = 1;
        i -= 2;
    }
    for (int i = 0;i <= ans.size();i++) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}