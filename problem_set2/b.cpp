#include<iostream>
#include<map>
using namespace std;

map<int, int>a;
int main() {
    int t;
    cin >> t;
    while (t--) {
        a.clear();
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            int t;
            cin >> t;
            if (a.find(t) == a.end()) {
                a[t] = 1;
            }
            else {
                a[t]++;
            }
        }
        for (int i = 1;i <= n;i++) {
            if (i <= a.size()) {
                cout << a.size() << " ";
            }
            else {
                cout << i << " ";
            }
        }
        cout << endl;
    }


    return 0;
}