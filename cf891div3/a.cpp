#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int numeven = 0;
        int numodd = 0;
        for (int i = 1;i <= n;i++) {
            int tmp;
            cin >> tmp;
            if (tmp % 2 == 0) {
                numeven++;
            }
            else {
                numodd++;
            }
        }
        if (numodd % 2 == 0) {
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}