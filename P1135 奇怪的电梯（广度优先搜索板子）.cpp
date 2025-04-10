#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1001;
int n,a,b,tmp;

struct floors{
    int up;
    int down;
    bool vis=false;
    int cnt=-1;
}f[205];

void bfs(int t){
    queue<int> q;
    q.push(t);
    f[t].cnt=0;
    f[t].vis=true;
    while(!q.empty()){
        int k=q.front();
        q.pop();
        int u=f[k].up,d=f[k].down;
        if(u>=1&&u<=n&&!f[u].vis){
            f[u].vis=true;
            q.push(u);
            f[u].cnt=f[k].cnt+1;
        }
        if(d>=1&&d<=n&&!f[d].vis){
            f[d].vis=true;
            q.push(d);
            f[d].cnt=f[k].cnt+1;
        }
        if(u==b||d==b) break;
    }
}

void solve(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        f[i].up=i+tmp;
        f[i].down=i-tmp;
        f[i].cnt=-1;
        f[i].vis=false;
    }
    bfs(a);
    cout<<f[b].cnt<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
