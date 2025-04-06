#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e7+10;
int n,k,l,r=0,ans=0;
int a[N],b[N];

bool check(int t){
	ll sum=0;
	for(int i=1;i<=n;i++){
		sum+=(a[i]/t)*(b[i]/t);
		if(sum>=k) return true;
	}
	return sum>=k;
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		r=max(r,max(a[i],b[i]));
	}
	l=1;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	solve();
    return 0;
}
