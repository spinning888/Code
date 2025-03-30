#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=10005;
int n,a[N],g[N][N],b[N],c[N],vis[N];
int ans=0,num=0;

void dfs(int x,int idx,int sum){
	if(sum>ans){
		ans=sum;
		num=idx;
		for(int i=0;i<num;i++){
			c[i]=b[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(g[x][i]&&!vis[i]){
			vis[i]=1;
			b[idx]=i;
			dfs(i,idx+1,sum+a[i]);
			vis[i]=0;
			b[idx]=0;
		}
	}
	return;
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int u;
			cin>>u;
			g[i][j]=u;
		}
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		b[0]=i;
		dfs(i,1,a[i]);
		vis[i]=0;
		b[0]=0;
	}
	for(int i=0;i<num;i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;
	cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	solve();
    return 0;
}