#include<iostream>
#include<algorithm>
using namespace std;

const int N = 15;
const int M = 11;
int a[N];

int hashcode(int x) {
    return x % M;
}

int main() {
    fill(a, a + N, -999);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (a[hashcode(t)] == -999) {
            a[hashcode(t)] = t;
        }
        else {
            int j = hashcode(t);
            while (j < N) {
                j++;
                if (a[j] == -999) {
                    a[j] = t;
                    break;
                }
            }
        }
    }
    for (int j = 0; j < N; j++) {
        cout << a[j] << " ";
    }
    cout << endl;
    int t;
    cin >> t;
    bool flag = 0;
    for (int i = hashcode(t);i < N;i++) {
        if (a[i] == t) {
            cout << "查找成功 " << i << endl;
            flag = 1;
            break;
        }
    }
    if (!flag) {
        int j = hashcode(t);
        if (a[j] == -999) {
            a[j] = t;
            cout << "插入成功 " << j << endl;
        }
        else
            while (j++) {
                if (j == N) {
                    j = 0;
                }
                if (a[j] == -999) {
                    a[j] = t;
                    cout << "插入成功 " << j << endl;
                    break;
                }
            }
    }
    return 0;

}