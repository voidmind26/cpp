#include<bits/stdc++.h>

using namespace std;
const int N = 5e5 + 10;
int tri[N][26];
int cnt;
int ed[N];

void insert(string a) {
    int st = 0;
    for (int i = 0;i < a.length();i++) {
        if (tri[st][a[i] - 'a'] == 0) {
            tri[st][a[i] - 'a'] = ++cnt;
            st = cnt;
        }
        else {
            st = tri[st][a[i] - 'a'];
        }
    }
    ed[st] = 1;
}

int find(string a) {
    int st = 0;
    for (int i = 0;i < a.length();i++) {
        if (tri[st][a[i] - 'a'] == 0) {
            return -1;
        }
        else {
            st = tri[st][a[i] - 'a'];
        }
    }
    if (ed[st] == 1) {
        ed[st]++;
        return 1;
    }
    else if (ed[st] == 0) {
        return -1;
    }
    else {
        return 2;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        string a;
        cin >> a;
        insert(a);
    }
    int m;
    cin >> m;
    for (int i = 1;i <= m;i++) {
        string a;
        cin>>a;
        int flag = find(a);
        if (flag == -1) {
            cout << "WRONG" << "\n";
        }
        if (flag == 1) {
            cout << "OK" << "\n";
        }
        if (flag == 2) {
            cout << "REPEAT" << "\n";
        }
    }

    return 0;
}