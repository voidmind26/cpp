#include<iostream>
#include<stack>
using namespace std;

int queen[9];
stack<int> s;
bool vis[9][9];
int sum = 0;

bool check(int row) {
    for (int i = 1; i < row; ++i) {
        if (vis[row][queen[row]] || queen[i] == queen[row] || abs(row - i) == abs(queen[row] - queen[i])) {
            return false;
        }
    }
    return true;
}

void dfs() {
    s.push(1);
    while (!s.empty()) {
        int cur = s.top();
        if (cur == 9) {
            sum++;
            s.pop();
            continue;
        }
        else {
            int flag = 0;
            for (int col = queen[cur] + 1; col < 9; ++col) {
                queen[cur] = col;
                if (check(cur)) {
                    flag = 1;
                    s.push(cur + 1);
                    break;
                }
            }
            if (!flag) {
                queen[cur] = 0;
                s.pop();
            }
        }
    }
}

int main(int argc, char const* argv[]) {
    dfs();
    cout << sum << endl;
    return 0;
}
