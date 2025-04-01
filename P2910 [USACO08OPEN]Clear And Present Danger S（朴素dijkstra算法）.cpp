#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=10005;
int n,m,ans=0;
int s[N],g[N][N],vis[N],dis[N];

int dijkstra(int x,int y){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[x]=0;
	for(int i=1;i<=n;i++){
		int u=-1;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&(u==-1||dis[j]<dis[u])) u=j;
		}
		vis[u]=1;
		for(int j=1;j<=n;j++){
			dis[j]=min(dis[j],dis[u]+g[u][j]);
		}
	}
	return dis[y];
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
		}
	}
	for(int i=1;i<m;i++){
		ans+=dijkstra(s[i],s[i+1]);
	}
	cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	solve();
    return 0;
}
