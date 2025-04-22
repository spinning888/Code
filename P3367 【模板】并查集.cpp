#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6;
int n, m,z,x,y;
int fa[N];

//路径压缩查找
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}

void unionset(int x,int y){
    fa[find(x)]=find(y);
}//还可以判断x,y的集合大小，将小集合并入大集合，加快后续查找速率

void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    while(m--){
        cin>>z>>x>>y;
        if(z==1) unionset(x,y);
        else{
            x=find(x),y=find(y);
            if(x==y) cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}    
