#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m;
int a[110][110],memo[110][110]={0};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int dfs(int x,int y){
    if(memo[x][y]) return memo[x][y];
    memo[x][y]=1;
    for(int i=0;i<4;i++){
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx<1||ty<1||tx>n||ty>m||a[tx][ty]>=a[x][y]) continue;
        memo[x][y]=max(memo[x][y],dfs(tx,ty)+1);
    }
    return memo[x][y];
}
void solve(){
   cin>>n>>m;
   int maxx=1;
   for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
           cin>>a[i][j];
       }
   }
   for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
            maxx=max(maxx,dfs(i,j));
        }
    }
    cout<<maxx<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}    
