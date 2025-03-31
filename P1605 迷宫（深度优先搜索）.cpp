#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=10005;
int n,m,t,sx,sy,tx,ty;;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int vis[N][N];
int ans=0;

void dfs(int x,int y){
	if(x==tx&&y==ty){
		ans++;
		return;
	}
	for(int i=0;i<4;i++){
		int kx=x+dx[i],ky=y+dy[i];
		if(kx>n||kx<=0||ky>m||ky<=0||vis[kx][ky]||vis[kx][ky]==-1) continue;
		vis[kx][ky]=1;
		dfs(kx,ky);
		vis[kx][ky]=0;	
	}
	return;
}

void solve(){
	cin>>n>>m>>t;
	cin>>sx>>sy>>tx>>ty;
	while(t--){
		int nx,ny;
		cin>>nx>>ny;
		vis[nx][ny]=-1;
	}
	vis[sx][sy]=1;
	dfs(sx,sy);
	cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	solve();
    return 0;
}
