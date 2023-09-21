#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 8;
int a[N][N];
bool f[N][N];
int n, m;
int tmp = 0;
int ans = -1;
void mem() {
    for (int i = 0;i <= n;i++) {
        f[0][i] = 1;
        f[i][0] = 1;
    }
}
void mark(int x,int y){
    
}
void dfs(int x, int y) {
    if(!f[x][y]){
        tmp+=a[x][y];
        ans=max(tmp,ans);
        mark()
    }
    

}
int main() {
    int t;
    cin >> t;
    for (int i = 1;i <= t;i++) {
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        for (int j = 1;j <= n;j++) {
            for (int k = 1;k <= m;k++) {
                cin >> a[j][k];
            }
        }
        mem();
        dfs(1, 1);
    }

    return 0
}