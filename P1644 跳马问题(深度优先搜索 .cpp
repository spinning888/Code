#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=10005;
int n,m;
int dx[4]={1,2,1,2};
int dy[4]={2,1,-2,-1};
int ans=0;

void dfs(int x,int y){
	if(x==m&&y==n){
		ans++;
		return;
	}
	for(int i=0;i<4;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if(tx>m||ty>n||ty<0) continue;
		dfs(tx,ty);
	}
	return;
}

void solve(){
	cin>>n>>m;
	int x=0,y=0;
	for(int i=0;i<4;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if(tx>m||ty>n||ty<0) continue;
		dfs(tx,ty);
	}
	cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	solve();
    return 0;
}
