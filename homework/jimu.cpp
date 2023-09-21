#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>
using namespace std;
int a[30][3];
int n;
void mem() {
    for (int i = 0;i < n;i++) {
        a[i][0] = -1;
        a[i][1] = i;
        a[i][2] = -1;
    }
}
void mv(int s, int e, int mode) {
    if (mode == 1) {
        int st = a[s][2];
        while (a[st][0] != -1 && st != -1) {//repalce
            a[st][0] = -1;
            a[st][1] = st;
            int tmp = st;
            st = a[st][2];
            a[tmp][2] = -1;
        }
        st = a[e][1];
        while (a[st][0] != -1 && st != -1) {
            a[st][0] = -1;
            a[st][1] = st;
            int tmp = st;
            st = a[st][2];
            a[tmp][2] = -1;
        }
        a[s][0] = e;
        a[s][1] = e;
        a[s][2] = -1;
        a[e][2] = s;
        return;
    }
    if (mode == 2) {
        int st = a[s][2];
        while (a[st][0] != -1 && st != -1) {//repalce
            a[st][0] = -1;
            a[st][1] = st;
            int tmp = st;
            st = a[st][2];
            a[tmp][2] = -1;
        }
        st = a[e][2];
        bool f = 1;
        while (a[st][2] != -1) {//find
            if (st == -1 && f) {
                st = e;
                break;
            }
            f = 0;
            st = a[st][2];
        }
        a[st][2] = s;
        a[s][0] = st;
        a[s][1] = e;
    }
}
void st(int s, int e, int mode) {
    if (mode == 1) {
        int st = a[e][2];
        while (a[st][0] != -1 && st != -1) {//repalce
            a[st][0] = -1;
            a[st][1] = st;
            int tmp = st;
            st = a[st][2];
            a[tmp][2] = -1;
        }
        a[s][0] = e;
        a[s][1] = a[e][1];
        a[e][2] = s;
        st = a[s][2];
        while (a[st][2] != -1 && st != -1) {//set line num
            a[st][1] = a[e][1];
            st = a[st][2];
        }
    }
    if (mode == 2) {
        if (a[s][1] == a[e][1]) {
            return;
        }
        int st = a[e][2];
        bool f = 1;
        while (a[st][2] != -1) {//find
            if (st == -1 && f) {
                st = e;
                break;
            }
            f = 0;
            st = a[st][2];
        }
        a[st][2] = s;
        a[a[s][0]][2] = -1;
        a[s][0] = st;
        a[s][1] = a[e][1];
        st = a[s][2];
        while (a[st][2] != -1 && st != -1) {//set line num
            a[st][1] = a[e][1];
            st = a[st][2];
        }

    }
}
void xh(int s, int e) {
    int tmp;
    s = a[s][1];
    e = a[e][1];
    tmp = a[e][2];
    a[e][2] = a[s][2];
    a[s][2] = tmp;
    int st = a[s][2];
    while (a[st][2] != -1 && st != -1) {//set line num
        a[st][1] = a[s][1];
        st = a[st][2];
    }
    st = a[e][2];
    while (a[st][2] != -1 && st != -1) {//set line num
        a[st][1] = a[e][1];
        st = a[st][2];
    }
}
int exp(char order[]) {
    int f = 0;
    int mode;
    int s, e;
    s = 0;
    e = 0;
    int l = strlen(order);
    if (order[0] == 'm') {
        f = 1;
    }
    if (order[0] == 's') {
        f = 2;
    }
    if (order[0] == 'x') {
        f = 3;
    }
    if (order[0] == 'q') {
        return -1;
    }
    bool flag = 1;
    bool digit2 = 1;
    for (int i = 3;i < l;i++) {
        if (isdigit(order[i])) {
            if (flag) {
                s += order[i] - '0';
                s *= 10;
            }

            else {
                e += order[i] - '0';
                e *= 10;
            }
        }
        else {
            if (digit2) {
                if (order[i + 2] == 'n') {
                    mode = 1;
                }
                if (order[i + 2] == 'v') {
                    mode = 2;
                }
                digit2 = 0;
            }
            flag = 0;

        }
    }
    e /= 10;
    s /= 10;
    switch (f) {
    case 1:
        mv(s, e, mode);
        break;
    case 2:
        st(s, e, mode);
        break;
    case 3:
        xh(s, e);
        break;
    default:
        break;
    }
    return 1;
}
int main() {
    cin >> n;
    mem();
    while (1) {
        char order[100];
        cin.getline(order, 100);
        if (exp(order) == -1) {
            break;
        }
    }
    for (int i = 0;i < n;i++) {
        cout << i << ": ";
        if (a[i][0] != -1) {
            cout << endl;
            continue;
        }
        else {
            int st = i;
            cout << st << " ";
            while (1) {
                st = a[st][2];
                if (a[st][2] != -1)
                    cout << st << " ";
                else {
                    cout << st;
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}