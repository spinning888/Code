#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=10005;
int n,tot=0;
int vis[N]={0},a[N];

bool is_prime(int x){
	if(x<=1) return false;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}

void dfs(int cnt){
	if(cnt==n&&is_prime(a[n]+a[1])){
		for(int i=1;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<a[n]<<endl;
		return;
	}
	for(int i=2;i<=n;i++){
		if(!vis[i]&&is_prime(a[cnt]+i)){//注意区分cnt,cnt-1,cnt+1
			vis[i]=1;
			a[cnt+1]=i;
			dfs(cnt+1);
			vis[i]=0;
		}
	}
	return;
}

void solve(){
	a[1]=1;
	vis[1]=1;
	while(cin>>n){
		tot++;
		if(tot>1) cout<<endl;
		cout<<"Case "<<tot<<":"<<endl;
		dfs(1);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	solve();
    return 0;
}
