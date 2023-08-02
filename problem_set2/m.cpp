#include<iostream>

using namespace std;

int mp[10][10];
int ans[10][10];
bool ckline[10][10];
bool ckcolunm[10][10];
bool cksqr[10][10];

int sqr(int x, int y) {
    if (x >= 1 && x <= 3) {
        if (y >= 1 && y <= 3)
            return 1;
        if (y >= 4 && y <= 6)
            return 4;
        if (y >= 7 && y <= 9)
            return 7;
    }
    if (x >= 4 && x <= 6) {
        if (y >= 1 && y <= 3)
            return 2;
        if (y >= 4 && y <= 6)
            return 5;
        if (y >= 7 && y <= 9)
            return 8;
    }
    if (x >= 7 && x <= 9) {
        if (y >= 1 && y <= 3)
            return 3;
        if (y >= 4 && y <= 6)
            return 6;
        if (y >= 7 && y <= 9)
            return 9;
    }
    return -1;
}

void dfs(int x, int y) {
    if (x >= 10 || y >= 10) {
        for (int i = 1;i <= 9;i++) {
            for (int j = 1;j <= 9;j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    if (mp[x][y] == 0) {
        for (int i = 1;i <= 9;i++) {
            if (!ckline[x][i] && !ckcolunm[y][i] && !cksqr[sqr(x, y)][i]) {
                ans[x][y] = i;
                ckline[x][i] = 1;
                ckcolunm[y][i] = 1;
                cksqr[sqr(x, y)][i] = 1;
                if (x != 9) {
                    dfs(x + 1, y);

                }
                else {
                    dfs(1, y + 1);
                }
                ckline[x][i] = 0;
                ckcolunm[y][i] = 0;
                cksqr[sqr(x, y)][i] = 0;
                ans[x][y] = 0;
            }
        }
    }
    else {
        if (x != 9) {
            dfs(x + 1, y);
        }
        else {
            dfs(1, y + 1);
        }
    }
}


int main() {
    for (int i = 1;i <= 9;i++) {
        for (int j = 1;j <= 9;j++) {
            cin >> mp[i][j];
        }
    }
    for (int i = 1;i <= 9;i++) {
        for (int j = 1;j <= 9;j++) {
            if (mp[i][j] != 0) {
                int t = mp[i][j];
                ans[i][j] = mp[i][j];
                ckline[i][t] = 1;
                ckcolunm[j][t] = 1;
                cksqr[sqr(i, j)][t] = 1;
            }
        }
    }
    dfs(1, 1);
    return 0;
}