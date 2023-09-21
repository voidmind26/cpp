#include<iostream>
using namespace std;

int main() {
    int a[5];
    int start[5];
    int d;
    int i = 0;
    while (cin >> a[1]) {
        cin >> a[2] >> a[3] >> a[4];
        cin >> start[1] >> start[2] >> start[3] >> start[4];
        cin >> d;
        int ff = 0;
        cout << "Case " << ++i << ": ";
        for (int i = start[1] + a[1];i <= 365 + a[1] * a[2] * a[3] * a[4];i += a[1]) {
            int f = 1;
            for (int j = 2;j <= 4;j++) {
                if ((i - start[j]) % a[j] != 0) {
                    f = 0;
                }
            }
            if(i<=d){
                continue;
            }
            if (f) {
                ff = 1;
                cout << i - d << endl;
                break;
            }
        }
        if (!ff) {
            cout << "No such days." << endl;
        }

    }
    return 0;
}
