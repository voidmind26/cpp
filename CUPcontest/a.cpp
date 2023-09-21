#include<iostream>
#include<string>
using namespace std;

int main() {
    int t;
    cin >> t;
    int sum = 0;
    while (t--) {
        string a;
        string ans;
        cin >> a;
        for (int i = 0;i < a.length();i++) {
            if (a[i] == '0') {
                ans.push_back(char(sum + 'a' - 1));
                sum = 0;
            }
            else {
                sum += a[i] - '0';
            }
        }
        ans.push_back(char(sum + 'a' - 1));
        sum = 0;
        cout<<ans<<endl;
    }

    return 0;
}