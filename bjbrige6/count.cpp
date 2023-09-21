#include<string>
#include<iostream>
#include<set>

using namespace std;

set<string>s;

int main() {
    string a;
    while (cin >> a) {
        s.clear();
        int l = a.size();
        for (int i = 0; i < l; i++) {
            for (int j = 1; j + i <= l; j++) {
                s.insert(a.substr(i, j));
            }
        }
        cout << a.length() << " " << s.size() << endl;
    }
    return 0;
}