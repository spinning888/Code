#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+10;
int n,m,l,r;
int a[N];

bool is_prime(int x){
	if(x<2) return false;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		if(is_prime(i)) a[i]++;
		a[i]+=a[i-1];
	}
	while(n--){
		cin>>l>>r;
		if(l<1||r>m){
			cout<<"Crossing the line"<<endl;
			continue;
		}
		cout<<a[r]-a[l-1]<<endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	solve();
    return 0;
}
