#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,tx,ty;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char tc,a[305][305];
struct node{
    int x,y;
    int step;
    node(int x,int y,int step):x(x),y(y),step(step){}
};
queue<node>q;

//构造结构体模拟机器的传送
struct machine{
    int x1,y1,x2,y2;
}p[26];

void bfs(){
    while(!q.empty()){
        node t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            tx=t.x+dx[i];
            ty=t.y+dy[i];
            tc=a[tx][ty];
            if(tx<1||tx>n||ty<1||ty>m||tc=='#')continue;
            if(tc=='.'){
                q.push(node(tx,ty,t.step+1));
                a[tx][ty]='#';
            }
            if(tc=='='){
                cout<<t.step+1<<endl;
                return;
            }
          //存在多次使用机器的最佳方案，故不可以置为#
            if(tc>='A'&&tc<='Z'){
                int idx=tc-'A';
                if(p[idx].x1==tx&&p[idx].y1==ty){
                    q.push(node(p[idx].x2,p[idx].y2,t.step+1));
                }else if(p[idx].x2==tx&&p[idx].y2==ty){
                    q.push(node(p[idx].x1,p[idx].y1,t.step+1));
                }
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            tc=a[i][j];
            if(tc>='A'&&tc<='Z'){
                int idx=tc-'A';
                if(p[idx].x1==0){
                    p[idx].x1=i;
                    p[idx].y1=j;
                }else{
                    p[idx].x2=i;
                    p[idx].y2=j;
                }
            }else if(a[i][j]=='@'){
                q.push(node(i,j,0));
                a[i][j]='#';
            }
        }
    }
    bfs();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
