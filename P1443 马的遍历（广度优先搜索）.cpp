#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1001;
int m,n,x,y,ans=0;
int a[N][N],vis[N][N];
int dx[8]={1,2,-2,-1,1,2,-2,-1};
int dy[8]={2,1,1,2,-2,-1,-1,-2};

void bfs(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y]=0;
    while(!q.empty()){
        auto[cx,cy]=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int xx=cx+dx[i];
            int yy=cy+dy[i];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&vis[xx][yy]==-1){
                vis[xx][yy]=vis[cx][cy]+1;
                q.push({xx,yy});
            }
        }
    }
}

void solve(){
    cin>>n>>m>>x>>y;
    memset(vis,-1,sizeof(vis));
    bfs(x,y);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<setw(5)<<left<<vis[i][j]<<(j==m?"\n":" ");
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
