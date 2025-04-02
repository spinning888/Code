#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+10;
int n,k;
ll maxx=0,ans=0;
ll a[N],b[N];


void solve(){
	cin>>n>>k;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];//前缀和
	}
	for(int i=1;i+k<=n;i++){
		maxx=max(maxx,b[i+k]-b[i]);
	}
	ans=b[n]-maxx;
	cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	solve();
    return 0;
}
