#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=10005;
int a[N][N];
int n,m,ans=0;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

void dfs(int x,int y){
	for(int i=0;i<8;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(a[nx][ny]==1){
			a[nx][ny]=0;//技巧搜索后置为干地
			dfs(nx,ny);
		}
	}
	return;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;
			cin>>c;
			if(c=='.') a[i][j]=0;
			else a[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==1){
				ans++;
				dfs(i,j);
		    }
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
