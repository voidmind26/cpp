#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int a[12];
int sorted[12];
char flag[12][12] = { "富强", "民主", "文明" ,"和谐" ,"自由" ,"平等" ,"公正" ,"法治" ,"爱国" ,"敬业" ,"诚信" ,"友善" };

int mergefind(int val, int l, int r) {
    if (l >= r) {
        return l;
    }
    int mid = (l + r) / 2;
    if (val > sorted[mid]) {
        return mergefind(val, mid + 1, r);
    }
    else {
        return mergefind(val, l, mid);
    }
}
void ins(int pos, int val, int n) {
    if (pos == n) {
        sorted[n] = val;
        return;
    }
    for (int i = n;i > pos; i--) {
        sorted[i] = sorted[i - 1];
    }
    sorted[pos] = val;
}

int main() {
    bool wrong = false;
    for (int i = 0; i < 12; i++) {
        bool check = false;
        char tmp[10];
        cin >> tmp;
        for (int j = 0; j < 12; j++) {
            if (strcmp(tmp, flag[j]) == 0) {
                a[i] = j;
                check = true;
                break;
            }
        }
        if (!check) {
            wrong = true;
        }
    }
    if (wrong) {
        cout << "Wrong" << endl;
        return 0;
    }

    for (int i = 0; i < 12; i++) {
        ins(mergefind(a[i], 0, i), a[i], i);
    }
    for (int i = 1; i < 12; i++) {
        if (sorted[i] != sorted[i - 1] + 1) {
            wrong = true;
        }
    }
    if (wrong) {
        cout << "Wrong" << endl;
        return 0;
    }
    for (int i = 0; i < 12; i++) {
        cout << flag[sorted[i]] << " ";
    }
    cout << endl;
    return 0;
}
