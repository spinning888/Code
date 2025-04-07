#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1000010;
int n,t,l,r,ans=0;
int a[N];
priority_queue<int,vector<int>,greater<int>>q;

bool check(int k){
	for(int i=1;i<=k;i++){
		q.push(a[i]);
	}
	for(int i=k+1;i<=n;i++){
		int k=q.top()+a[i];
		if(k>t) return false;
		q.pop();
		q.push(k);
	}
	for(int i=1;i<k;i++) q.pop();
	return q.top()<=t;
}

void solve(){
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	l=1,r=n;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
