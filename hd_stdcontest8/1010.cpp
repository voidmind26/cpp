#include<iostream>
using namespace std;
typedef long long ll;
bool check(ll x){
	ll sq=sqrt(x);
	return sq*sq==x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--){
		ll a,b;cin>>a>>b;
		ll cha=abs(a-b);
		if(check(cha)) cout<<"1\n";
		else {
			if(cha%4!=2) cout<<"2\n";
			else {
				if((cha-2)%8==0) cout<<"2\n";
				else cout<<"3\n";
			}
		}
	}
}