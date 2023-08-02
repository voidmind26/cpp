#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

#define int long long
using namespace std;
const int N = 4e6 + 1;

struct node {
    int data, index;

    node() {}
    node(int a, int b) :data(a), index(b) {}

    bool operator < (const node& T)const {
        return data < T.data;
    }
};

vector<node>save;
vector<int>tmp;
int num[N];

inline int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-')w = -1;ch = getchar(); }//如果输入
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();//输入数字并统计
    return s * w;//输出结果
}

signed main() {
    int t;
    ios::sync_with_stdio(false);
    t = read();
    while (t--) {
        save.clear();
        int n;
        n = read();
        for (int i = 1;i <= n;i++) {
            num[i] = 0;
            int t;
            t=read();
            tmp.clear();
            for (int j = 1;j <= t;j++) {
                int x;
                x = read();
                tmp.push_back(x);
            }
            sort(tmp.begin(), tmp.end());
            unique(tmp.begin(), tmp.end());
            for (auto j : tmp) {
                save.push_back(node(j, i));
            }
        }
        // for (auto i : save) {
        //     cout << i.data << " " << i.index << endl;
        // }
        sort(save.begin(), save.end());
        int l = 0;
        int r = 0;
        int cur = 0;
        int ans = 1e18;
        int len = save.size();
        for (r = 0;r < len;r++) {
            if (num[save[r].index] == 0) {
                cur++;
            }
            num[save[r].index]++;
            if (cur == n) {
                break;
            }
        }
        ans = save[r].data - save[l].data;
        while (r < len) {
            if (cur >= n) {
                ans = min(ans, save[r].data - save[l].data);
                num[save[l].index]--;
                if (num[save[l].index] == 0) {
                    cur--;
                }
                l++;
            }
            else {
                r++;
                if (r == len)
                    break;
                if (num[save[r].index] == 0) {
                    cur++;
                }
                num[save[r].index]++;
            }
        }
        cout << ans << endl;
    }
    // system("pause");
    return 0;
}