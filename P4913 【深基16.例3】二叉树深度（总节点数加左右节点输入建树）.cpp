#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6;
int n,ans=0;

struct node{
    int l,r;
}tree[N];

void dfs(int pos,int deep){
    if(!tree[pos].l&&!tree[pos].r){
        ans=max(ans,deep);
        return;
    }
    dfs(tree[pos].l,deep+1);
    dfs(tree[pos].r,deep+1);
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tree[i].l>>tree[i].r;
    }
    dfs(1,1);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}    
