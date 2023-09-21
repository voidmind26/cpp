#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

const int N = 200005;
int a[N];
int b[N];
map<int,int> mp;

int main() {
    int t;
    cin >> t;
    while (t--) {
        mp.clear();
        int n;
        memset(a, 0, sizeof(a));
        cin >> n;
        for (int i = 0;i < n;i++) {
            int t;
            cin>>t;
            if(mp.find(t) == mp.end()){
                mp[t]++;
            }
        }
        
        if (n >= 3) {
            for (int i = 0;i < n;i++) {
                if(i%2==0){
                    b[i]=a[n/2+i/2];
                }
                else {
                    b[i]=a[i/2];
                }
            }
            int ans = 0;
            for (int i = 0;i < n - 2;i++) {
                if (ans != b[i] + b[i + 1]) {
                    cout << ans << endl;
                    break;
                }
                else {
                    ans++;
                }
            }
        }
        else {
            if (a[0] + a[1] == 0) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}