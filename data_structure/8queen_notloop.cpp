#include<iostream>

using namespace std;

int queen[9];

int sum = 0;

bool check(int row) {
    for (int i = 1; i < row; ++i) {
        if (queen[i] == queen[row] || abs(row - i) == abs(queen[row] - queen[i])) {
            return false;
        }
    }
    return true;
}

void dfs(int row) {
    if (row == 9) {
        sum++;
    }
    else {
        for (int col = 1; col < 9; ++col) {
            queen[row] = col;
            if (check(row)) {
                dfs(row + 1);
            }
        }
    }
}

int main(int argc, char const* argv[]) {
    dfs(1);
    cout << sum << endl;
    return 0;
}
