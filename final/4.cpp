#include<algorithm>
#include<iostream>
#include<set>
#include<list>
using namespace std;
set <int> a;
list <int> l;
int main() {
    int n, m;
    cin >> n >> m;
    list<int>::iterator it;
    for (int i = 1;i <= n;i++) {
        int flag, var;
        cin >> flag;
        int tmp = -1;
        if (flag == 1) {
            cin >> var;
            a.insert(var);
            if (var != tmp) {
                l.push_front(var);
                tmp = var;
            }
        }
        else {
            int f = 0;
            while (a.size() < m) {
                it = l.begin();
                a.insert(*it);
                it++;
                if (it == l.end() && a.size() < m) {
                    f = 1;
                    break;
                }
            }
            if (f) {
                cout << -1 << endl;
                break;
            }
            cout << *it << endl;

        }
    }
    return 0;
}