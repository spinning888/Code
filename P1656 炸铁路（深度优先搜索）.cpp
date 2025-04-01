#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=10005;
int n,m,a,b;
typedef pair<int,int> p;
int g[N][N],vis[N];
vector<p> v;

int dfs(int x){
	vis[x]=1;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]&&g[x][i]){
			int s=dfs(i);
			sum+=s;
		}
	}
    return sum+1;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		g[a][b]=1;
		g[b][a]=1;
		if(a>b) swap(a,b);
		v.push_back({a,b});
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		p t=v[i];
		int x=t.first,y=t.second;
		g[x][y]=0;
		g[y][x]=0;
		memset(vis,0,sizeof(vis));
		if(dfs(x)!=n) cout<<x<<" "<<y<<endl;
		g[x][y]=1;
		g[y][x]=1;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	solve();
    return 0;
}
