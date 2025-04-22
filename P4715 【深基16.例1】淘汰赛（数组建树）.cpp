#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6;
int n;

struct node{
    int val,num;
}tree[N];


void solve(){
    cin>>n;
    int t=1;
    for(int i=(1<<n);i<(1<<(n+1));i++){
        cin>>tree[i].val;
        tree[i].num=t;
        t++;
    }
    for(int i=((1<<n)-1);i>=1;i--){
        if(tree[2*i].val>tree[2*i+1].val) tree[i]=tree[2*i];
        else tree[i]=tree[2*i+1];
    }
    if(tree[2].val>tree[3].val) cout<<tree[3].num;
    else cout<<tree[2].num;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}    
