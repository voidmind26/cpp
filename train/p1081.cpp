#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;
int a[N];
int q[N];

priority_queue<int, vector<int>, greater<int> >small_heap;
priority_queue<int, vector<int>, less<int> >big_heap;

int main() {
    int n, m;
    cin >> m >> n;
    for (int i = 1;i <= m;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> q[i];
    }
    int num = 1;
    int pos = 1;
    for (int i = 1;i <= n;i++) {
        while (pos <= q[i]) {
            big_heap.push(a[pos]);
            while (big_heap.size() > num) {
                small_heap.push(big_heap.top());
                big_heap.pop();
            }
            pos++;
        }
        while (big_heap.size() < num) {
            big_heap.push(small_heap.top());
            small_heap.pop();
        }
        cout << big_heap.top() << "\n";
        num++;
        while (big_heap.size() < num&&!small_heap.empty()) {
            big_heap.push(small_heap.top());
            small_heap.pop();
        }
    }
    return 0;
}

/*

10 6
10 9 8 7 6 5 4 3 2 1
10 10 10 10 10 10

*/