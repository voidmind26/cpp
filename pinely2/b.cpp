#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 1e5 + 1;
int a[N];
int save[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> save[i];
        }
        for (int i = 1;i <= n;i++) {
            a[save[i]]=i;
        }
        int ans=0;
        for(int i=2;i<=n;i++){
            if(a[i]<a[i-1]){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
