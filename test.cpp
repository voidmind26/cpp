#include<iostream>
#include<vector>
using namespace std;
vector<int>prime;

bool check(int x) {
    bool res = 1;
    for (int i = 2;i <= (int)sqrt(x);i++) {
        if (x % i == 0) {
            res = 0;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    prime.push_back(1);
    for (int i = 2;i <= n;i++) {
        if (check(i)) {
            prime.push_back(i);
        }
    }
    for (auto i : prime) {
        for (auto j : prime) {
            cout << i + j << " ";
        }
        cout << endl;
    }
    return 0;
}